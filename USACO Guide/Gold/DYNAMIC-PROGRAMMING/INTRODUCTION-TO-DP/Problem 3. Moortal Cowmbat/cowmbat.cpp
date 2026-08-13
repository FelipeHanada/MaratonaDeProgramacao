#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<int>> a(m, vector<int>(m));
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for (int k=0; k<m; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    vector<vector<int>> cost(m, vector<int>(n+1));
    for (int c=0; c<m; c++) {
        cost[c][0] = 0;
        for (int i=1; i<=n; i++) cost[c][i] = cost[c][i-1] + a[s[i-1]-'a'][c];
    }


    vector<int> ans(n+1, INT32_MAX);
    ans[0] = 0;
    vector<vector<int>> dp(m, vector<int>(n+1, INT32_MAX));
    for (int i=1; i<=n; i++) {
        for (int c=0; c<m; c++) {
            if (i >= k && ans[i-k] != INT32_MAX) dp[c][i] = min(dp[c][i], ans[i-k] + cost[c][i] - cost[c][i-k]);
            if (dp[c][i-1] != INT32_MAX) dp[c][i] = min(dp[c][i], dp[c][i-1] + a[s[i-1]-'a'][c]);

            ans[i] = min(ans[i], dp[c][i]);
        }
    }

    cout << ans[n] << '\n';
}