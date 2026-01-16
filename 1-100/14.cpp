#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e6+10;

vector<ll> collatz(maxN);
ll cal_collatz(ll n) {
    if (n==1) return 1;
    if (n<maxN && collatz[n]) return collatz[n];
    if (n%2) return 1 + cal_collatz(n*3+1);
    else return 1 + cal_collatz(n/2);
    return collatz[n];
}
void solve() {
    ll ans, mx=1;
    for (int i=1; i<=1e6; i++) {
        collatz[i] = cal_collatz(i);
        if (collatz[i] > mx) ans = i, mx=collatz[i];
    }
    cout << ans << ' ' << mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
