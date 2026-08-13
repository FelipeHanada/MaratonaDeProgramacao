#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(n, { -1, 0 }));
    for (int i=0; i<n; i++) dp[1][i] = { a[i], a[i] };
    
    for (int len=2; len<=n; len++) {
        for (int i=0; i+len<=n; i++) {

            for (int left=1; left<len; left++) {
                dp[len][i].second = max(dp[len][i].second, max(dp[left][i].second, dp[len-left][i+left].second));
                if (dp[left][i].first != -1 && dp[left][i].first == dp[len-left][i+left].first) {
                    dp[len][i].first = dp[left][i].first + 1;
                    dp[len][i].second = max(dp[len][i].second, dp[len][i].first);
                }
            }

        }
    }

    cout << dp[n][0].second << '\n';
}
