#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

void solve() {
    // a = u^2-v^2, b = 2uv, c = u^2+v^2
    // 2u^2+2uv = n
    // gcd(a, b)=1
    // a+b+c=2u(u+v)d
    int s; cin >> s; // 1000
    s >>= 1;
    for (int m=2; m*m<=s; m++) {
        if (s%m!=0) continue;
        int sm = s/m;
        while (!(sm&1)) sm >>= 1;
        int k = m&1 ? m+2 : m+1;
        for (;k<=sm && k < 2*m; k+=2) {
            if ((sm % k == 0) && __gcd(m, k)==1) {
                int d = s/(m*k);
                int n = k-m;
                int a = d*(m*m-n*n);
                int b = 2*d*m*n;
                int c = d*(m*m+n*n);
                cout << a << ' ' << b << ' ' << c << ' ' << a*b*c;
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
