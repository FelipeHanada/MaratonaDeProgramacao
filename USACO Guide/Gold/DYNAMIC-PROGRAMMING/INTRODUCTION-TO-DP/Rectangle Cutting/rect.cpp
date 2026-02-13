#include <bits/stdc++.h>
using namespace std;



int main() {
    int a, b;
    cin >> a >> b;

    int dp[a+1][b+1];

    dp[1][1] = 0;
    for (int i=2; i<=a; i++) dp[i][1] = i-1;
    for (int i=2; i<=b; i++) dp[1][i] = i-1;

    for (int i=2; i<=a; i++) {
        for (int j=2; j<=b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = INT32_MAX;
            for (int ci=1; ci<i; ci++)
                dp[i][j] = min(dp[i][j], 1 + dp[ci][j] + dp[i-ci][j]);
            for (int cj=1; cj<j; cj++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][cj] + dp[i][j - cj]);
        }
    }

    cout << dp[a][b] << '\n';
}
