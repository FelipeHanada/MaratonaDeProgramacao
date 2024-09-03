#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    for (int test=0; test<t; test++) {
        int n; cin >> n;
        int a[n];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        int dp[2][n+1];
        fill_n(dp[0], n + 1, 1e9);
        fill_n(dp[1], n + 1, 1e9);
        // dp[i][j] = minimum number of skips on the ith player (0 = friend) jth turn;
        dp[0][0] = 0; // best case before the 0'th choice
        for (int i=0; i<n; i++) {
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i]);
            // calculating friends turn on i+1 coming from our single turn
            dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + a[i]);
            // calculating our turn on i+1 coming from their single turn

            if (i + 2 <= n) {
                dp[0][i + 2] = min(dp[0][i + 2], dp[1][i]);
                // calculating friends turn on i+2 coming from our double turn
                dp[1][i + 2] = min(dp[1][i + 2], dp[0][i] + a[i] + a[i + 1]);
                // calculating our turn on i+2 coming from their double turn
            }
        }

        cout << min(dp[0][n], dp[1][n]) << endl;
    }
}
