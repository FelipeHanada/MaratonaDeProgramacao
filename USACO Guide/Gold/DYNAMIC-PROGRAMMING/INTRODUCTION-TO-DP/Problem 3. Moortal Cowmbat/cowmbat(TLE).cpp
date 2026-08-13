#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<int>> cost(m, vector<int>(m));
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            cin >> cost[i][j];

    // floyd warshall
    for (int k=0; k<m; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    for (int k=0; k<m; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    for (int k=0; k<m; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    vector<vector<int>> dp(m, vector<int>(k, INT32_MAX));
    for (int c=0; c<m; c++)
        dp[c][k-1] = cost[s[0]-'a'][c];

    for (int i=1; i<n; i++) {
        vector<vector<int>> next(m, vector<int>(k, INT32_MAX));
        for (int c=0; c<m; c++) {
            for (int r=0; r<k-1; r++) if (dp[c][r+1] != INT32_MAX) {
                next[c][r] = dp[c][r+1] + cost[s[i]-'a'][c];
            }

            if (dp[c][0] != INT32_MAX)
                next[c][0] = min(next[c][0], dp[c][0] + cost[s[i]-'a'][c]);

            for (int cc=0; cc<m; cc++) if (dp[cc][0] != INT32_MAX) {
                next[c][k-1] = min(next[c][k-1], dp[cc][0] + cost[s[i]-'a'][c]);
            }
        }

        swap(dp, next);
    }

    int ans = INT32_MAX;
    for (int c=0; c<m; c++) ans = min(ans, dp[c][0]);
    cout << ans << '\n';
}


/*
dp[i][j] = menor custo para o prefixo atual
        de modo que a última letra é i e ela foi repetida j vezes

O(|S|*k*m) = O(N*k*m) ----> TLE

se a letra lida atualmente for c,
    dp[i][j] = dp[i][j-1] + cost[c][i] 
*/
