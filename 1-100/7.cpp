#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

bool check_prime(int n) {
    if (n==1) return false;
    if (n<4) return true;
    if (n%2==0) return false;
    if (n<9) return true;
    if (n%3==0) return false;
    for (int i=5; i*i<=n; i+=6) {
        if (n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
void solve() {
    int n; cin >> n;
    vector<int> primes;
    int curr = 2;
    while (primes.size()<n) {
        if (check_prime(curr)) primes.push_back(curr);
        curr++;
    }
    cout << primes.back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
