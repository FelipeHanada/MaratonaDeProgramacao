#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e4;
constexpr int MAX_K = 1e3;
int n, k, a[MAX_N];
int dp[MAX_N + 1];
// dp[i]: max sum for a sequence with a subset that ends in i


int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    cin >> n >> k;
    for (int i=0; i<n; i++) { cin >> a[i]; }


    for (int i=0; i<n+1; i++) { fill_n(dp[i], k, 0); }
    for (int i=0; i<=n; i++) {

    }

    cout << dp[0][n] << endl;
}