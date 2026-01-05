#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

vector<int> primes;
void init() {
    vector<bool> prime(1e6+1);
    for (int i=2; i*i<=1e6; i++)
        if (!prime[i]) {
            for (int j=i*i; j<=1e6; j+=i)
                prime[j]=1;
            primes.push_back(i);
        }
}
ll bin_pow(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y&1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    ll ans = 1;
    for (auto &p: primes) {
        if (p>n) break;
        if (p*p>n) {
            ans *= p;
        } else {
            int pow = log(n) / log(p);
            ans *= bin_pow(p, pow);
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
