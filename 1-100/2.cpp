/*
Time: O(log n)
Space: O(1)
Problem: https://projecteuler.net/problem=2
Intuition: Use matmul to quickly generate 3th, 6th, 9th fib number using ((1 1)(1 0))^3

Input:
100

Output:
44

Input:
4000000

Output:
4613732
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll oo = 1e9 + 7, maxN = 3e3 + 5;

struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
              }
          }
        }
        return c;
    }
};

void solve() {
    int n; cin >> n;
    matrix base3{ {
      {3, 2},
      {2, 1}
    } };
    matrix curr{ {
      {1, 0},
      {0, 1}
    } };
    int ans = 0;
    while (true) {
        curr = curr * base3;
        if (curr.mat[0][1] > n) break;
        ans += curr.mat[0][1];
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve(), cout << '\n';   
}