#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 2e6+1;

int lpf[maxN];
void init() {
    for (int i=0; i<maxN; i++) lpf[i]=i;
    for (int i=2; i*i<maxN; i++) 
        if (lpf[i]==i)
            for (int j=i*i; j<maxN; j+=i)
                lpf[j] = i;
}
ll get_num_divisors(int a) {
    map<int, int> m;
    ll ans = 1;
    while (a>1) {
        m[lpf[a]]++;
        a /= lpf[a];
    }
    for (auto &i: m) ans *= i.second+1;
    return ans;
}
void solve() {
    // a = n*(n+1)/2
    // 2^2 * 7 -> 3 * 2 = 6
    // find n where n*(n+1)/2 has at least 500 divisors
    // n and n+1 is coprime
    ll n = 500, ans = 1;
    while (true) {
        ll a, b;
        if (ans%2==0) a = ans/2, b = ans+1;
        else a = ans, b = (ans+1)/2;
        if (get_num_divisors(a) * get_num_divisors(b) >= n) break;
        ans++;
    }
    cout << ans * (ans+1)/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
