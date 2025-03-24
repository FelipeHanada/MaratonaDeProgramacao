#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 100;
constexpr int MAX_X = 1e6;
int dp[MAX_X + 1];

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> c(n);
    fill_n(dp, x + 1, 0);
    for (int i=0; i<n; i++) {
        cin >> c[i];
        dp[c[i]] = 1;
    }
    sort(c.begin(), c.end());
    
    for (int i=c.front(); i<x; i++) {
        if (dp[i] == 0) continue;

        for (auto ci : c) {
            if (i + ci > x) break;
            dp[i + ci] = (dp[i + ci] + dp[i]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}
