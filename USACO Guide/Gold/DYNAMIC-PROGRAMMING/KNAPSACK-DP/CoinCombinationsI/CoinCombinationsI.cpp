#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 100, MAX_X = 1e6;

int n, x;
int c[MAX_N];
int dp[MAX_X];
// dp[i]: ways to sum i + 1

int main() {
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> c[i];
    sort(c, c+n);

    fill_n(dp, x, 0);
    for (int j=0; j<n; j++) {
        dp[c[j]-1] = 1;
    }

    for (int i=1; i<x; i++) {
        for (int j=0; j<n; j++) {
            if (i - c[j] < 0) continue; 
            dp[i] = (dp[i] + dp[i - c[j]]) % (int)(1e9+7);
        }
    }

    cout << dp[x - 1] << endl;
}