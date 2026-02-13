#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = max(
                max(dp[i-1][j], dp[i][j-1]),
                dp[i-1][j-1] + ((b[i-1] == a[j-1]) ? 1 : 0)
            );
        }
    }

    cout << dp[m][n] << '\n';

    stack<int> sol;
    int i=m, j=n;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else {
            sol.push(b[i-1]);
            i--; j--;
        };
    }

    while (!sol.empty()) {
        cout << sol.top() << ' ';
        sol.pop();
    }
    cout << '\n';
}
