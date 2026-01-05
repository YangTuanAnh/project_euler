/*
Time: O(n^(1/4))
Space: O(log n)
Problem: https://projecteuler.net/problem=3
Intuition: Pollard-Rho to generate divisors in O(n^(1/4)) and sporadically check for primes.
For small numbers (<= 1e5), we check directly with a sieve.
For larger numbers, we use Miller–Rabin.

Input:
13195

Output:
29

Input:
600851475143

Output:
6857
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll LIMIT = 100000;

vector<bool> is_prime_sieve;

void init_sieve() {
    is_prime_sieve.assign(LIMIT + 1, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false;
    for (ll i = 2; i * i <= LIMIT; i++) {
        if (is_prime_sieve[i]) {
            for (ll j = i * i; j <= LIMIT; j += i)
                is_prime_sieve[j] = false;
        }
    }
}

ll binpow(ll x, ll y, ll m) {
    ll ans = 1;
    x %= m;
    while (y) {
        if (y & 1) ans = (__uint128_t)ans * x % m;
        x = (__uint128_t)x * x % m;
        y >>= 1;
    }
    return ans;
}

bool miller_rabin(ll n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (ll a : {2, 3, 5, 7}) {
        if (a >= n) continue;
        ll x = binpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = (__uint128_t)x * x % n;
            if (x == n - 1) { composite = false; break; }
        }
        if (composite) return false;
    }
    return true;
}

ll rho(ll n, ll x0 = 2, ll c = 1) {
    if (n % 2 == 0) return 2;
    ll x = x0, y = x0, g = 1;
    while (g == 1) {
        x = ((__uint128_t)x * x % n + c) % n;
        y = ((__uint128_t)y * y % n + c) % n;
        y = ((__uint128_t)y * y % n + c) % n;
        g = gcd(abs(x - y), n);
    }
    if (g == n) return rho(n, x0 + 1, c + 1);
    return g;
}

void factorize(ll n, vll &factors) {
    if (n == 1) return;

    if (n <= LIMIT) {
        if (is_prime_sieve[n]) {
            factors.push_back(n);
            return;
        }
    } else {
        if (miller_rabin(n)) {
            factors.push_back(n);
            return;
        }
    }

    ll divisor = rho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}

void solve() {
    ll n; cin >> n;
    vll factors;
    factorize(n, factors);
    cout << *max_element(factors.begin(), factors.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_sieve();

    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
    return 0;
}
