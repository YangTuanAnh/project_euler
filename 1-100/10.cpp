#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

void solve() {
    int N = 2e6;
    vector<bool> primes(N+1);
    ll ans = 0;
    for (ll i=2; i<=N; i++)
        if (!primes[i]) {
            ans += i;
            if (i*i<=N)
                for (ll j=i*i; j<=N; j+=i) primes[j] = 1;
        }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
