/*
Time: O(1)
Space: O(1)
Problem: https://projecteuler.net/problem=1
Intuition: inclusion-exclusion

Input:
10

Output:
23

Input:
1000

Output:
233168
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e3 + 5;

void solve() {
    int n; cin >> n; n--;
    int a = n/3, b=n/5, c=n/15;
    cout << (a*(a+1)*3 + b*(b+1)*5 - c*(c+1)*15)/2;
}

int main(int argc, char* argv[]) {
    // cd cpp && g++ 1.cpp -o 1 && ./1 < "../tests/1/1.inp" > "../tests/1/1.out"
    // cd cpp && g++ 1.cpp -o 1 && ./1 < "../tests/1/2.inp" > "../tests/1/2.out"
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}