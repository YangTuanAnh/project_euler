#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

void solve() {
    int n; cin >> n;
    int sum = n*(n+1)/2, sum_sq = (2*n+1)*(n+1)*n/6;
    cout << sum*sum-sum_sq;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
