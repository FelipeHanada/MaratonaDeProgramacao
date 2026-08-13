#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> dp(k+1, vector<int>(n, INT32_MAX));
    // dp[i][j] = menor quantidade de espaço sobrando, com i mudanças e tamanho a[j] de rede
    for (int i=0; i<n; i++) {
        dp[0][i] = 0;
    }
    for (int i=0; i<n; i++) {
        vector<vector<int>> next(k+1, vector<int>(n, INT32_MAX));

        // mantendo ela igual
        for (int x=0; x<=k; x++) {
            for (int y=0; y<n; y++) {
                if (dp[x][y] == INT32_MAX) continue;

                if (a[y] >= a[i])
                    next[x][y] = dp[x][y] + a[y] - a[i];
            }
        }

        // mudando o tamanho da rede
        for (int x=1; x<=k; x++) {
            int mini = INT32_MAX;
            for (int y=0; y<n; y++) {
                mini = min(mini, dp[x-1][y]);
            }

            if (mini == INT32_MAX) continue;

            for (int y=0; y<n; y++) {
                if (a[y] >= a[i])
                    next[x][y] = min(next[x][y], mini + a[y] - a[i]);
            }
        }

        swap(dp, next);
    }

    int ans = INT32_MAX;
    for (int x=0; x<=k; x++) {
        for (int y=0; y<n; y++) {
            ans = min(ans, dp[x][y]);
        }
    }

    cout << ans << '\n';
}