#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e6+10;


void solve() {
    ll n; cin >> n;
    ll ans = 1;
    for (int i=0; i<n; i++) {
        ans *= 2*n-i;
        ans /= i+1;
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
