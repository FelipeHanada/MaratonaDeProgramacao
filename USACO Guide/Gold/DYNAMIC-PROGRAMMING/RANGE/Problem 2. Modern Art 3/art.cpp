#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(n, INT32_MAX));
    fill(dp[1].begin(), dp[1].end(), 1);

    for (int len=2; len<=n; len++) {
        for (int i=0; i+len<=n; i++) {
            for (int left=1; left<len; left++) {
                dp[len][i] = min(dp[len][i], dp[left][i] + dp[len-left][i+left] - int(a[i] == a[i+len-1]));
            }
        }
    }

    cout << dp[n][0] << '\n';
}