#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

void solve() {
    int n; cin >> n;
    int a[n][n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            if (i+4<n) {
                int verr = 1;
                for (int k=0; k<4; k++) verr *= a[i+k][j];
                ans = max(ans, verr);
            }
            if (j+4<n) {
                int horr = 1;
                for (int k=0; k<4; k++) horr *= a[i][j+k];
                ans = max(ans, horr);
            }
            if (i+4<n && j+4<n) {
                int down = 1;
                for (int k=0; k<4; k++) down *= a[i+k][j+k];
                ans = max(ans, down);
            }
            if (i-4>=0 && j+4<n) {
                int up = 1;
                for (int k=0; k<4; k++) up *= a[i-k][j+k];
                ans = max(ans, up);
            }
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
