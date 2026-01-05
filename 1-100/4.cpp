/*
Time: O(n^2)
Space: O(1)
Problem: https://projecteuler.net/problem=4
Intuition: The biggest palindrome has to be a factor of 111111, which can be broken down to either one divisible by 11 (prime). Go down from 999 to 100 and jump by 1 or 11.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 998244353, maxN = 3e5+5;

bool palin(int x) {
    int x0 = x, y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y == x0;
}
void solve() {
    int ans = 0, x, y;
    for (int i=999; i>=100; i--) {
        int j, jj;
        if (i%11==0) 
            j=999, jj=1;
        else 
            j=990, jj=11; 
        
        for (; j>=100; j-=jj)
            if (palin(i*j))
                if (ans < i*j) ans = i*j, x=i, y=j; 
                else break;
    }
        
    cout << ans << ' ' << x << ' ' << y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';
}
