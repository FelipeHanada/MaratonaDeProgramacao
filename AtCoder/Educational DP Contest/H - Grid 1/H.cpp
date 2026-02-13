#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9+7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> grid(h, vector<bool>(w, false));
    char c;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> c;
            grid[i][j] = (c == '#');
        }
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    for (int i=1; i<h && !grid[i][0]; i++) dp[i][0] = 1;
    for (int i=1; i<w && !grid[0][i]; i++) dp[0][i] = 1;
    for (int i=1; i<h; i++) {
        for (int j=1; j<w; j++) if (!grid[i][j]) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[h-1][w-1] << '\n';
}
