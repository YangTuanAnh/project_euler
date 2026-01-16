#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 2e6+1;

struct bigNum {
    string num;
    bigNum(string s) {
        num=s;
    }

    void add(string b) {
        int carry = 0;
        string a = num;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.length() < b.length()) swap(a, b);
        for (int i=0; i<b.length(); i++) {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            carry = sum / 10;
            a[i] = sum % 10 + '0';
        }
        for (int i=b.length(); i<a.length(); i++) {
            int sum = a[i] - '0' + carry;
            carry = sum / 10;
            a[i] = sum % 10 + '0';
        }
        if (carry) a += '0' + carry;
        reverse(a.begin(), a.end());
        num = a;
    }
};
void solve() {
    int n; cin >> n;
    string a[n]; for (auto &i: a) cin >> i;
    bigNum num(a[0]);
    for (int i=1; i<n; i++) num.add(a[i]);
    cout << num.num.substr(0, 10);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
