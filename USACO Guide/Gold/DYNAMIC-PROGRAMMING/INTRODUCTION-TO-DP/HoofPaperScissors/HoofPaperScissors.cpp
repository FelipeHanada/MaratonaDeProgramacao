#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_K = 20;
constexpr int MAX_N = 100000;

int n, k;
char a[MAX_N];
int dp[MAX_N+1][MAX_K+1][3];


int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> n >> k;

    for (int i=0; i<n; i++) cin >> a[i];

    // dp[i][j][g] most won games at the i'th game with j changes used with the g gesture on
    for (int i=0; i<n + 1; i++) {
        for (int j=0; j<k + 1; j++) {
            fill_n(dp[i][j], 3, 0);
        }
    }

    for (int i=0; i<n; i++) {
        int p[3] = {0};
        switch (a[i]) {
            case 'H': p[0]++; break;
            case 'P': p[1]++; break;
            case 'S': p[2]++; break;
        }

        for (int j=0; j<k; j++) {
            for (int g=0; g<3; g++) {
                dp[i + 1][j][g] = max(dp[i + 1][j][g], dp[i][j][g] + p[g]);

                for (int g2=0; g2<3; g2++) {
                    if (g == g2) continue;
                    dp[i + 1][j + 1][g] = max(dp[i + 1][j + 1][g], dp[i][j][g2] + p[g]);
                }
            }
        }

        for (int g=0; g<3; g++) {
            dp[i + 1][k][g] = max(dp[i + 1][k][g], dp[i][k][g] + p[g]);
        }
    }

    int ans = INT32_MIN;
    for (int j=0; j<k+1; j++) {
        for (int g=0; g<3; g++) {
            ans = max(ans, dp[n][j][g]);
        }
    }

    cout << ans << endl;
}