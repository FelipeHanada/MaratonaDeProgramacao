#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e4;
int dp[MAXN+1];
/* dp[i] = max value of a group ending immediately before to i (0-indexed)
d[0] = 0 starting situation (no group)

dp[i] = max(
    dp[i-1] + 1 * max(a[i-1 : i-1]),
    dp[i-2] + 2 * max(a[i-2 : i-1]),
    ...
    dp[i-j] + j * max(a[i-j : i-1]),
    ...
    dp[i-k] + k * max(a[i-k : i-1])
)
*/

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    dp[0] = 0;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];

        int mx = 0;
        for (int j=0; i-j >= 0 && j<k; j++) {
            mx = max(mx, a[i-j]);
            dp[i+1] = max(dp[i+1], dp[i-j] + (j+1) * mx);
        }
    }

    cout << dp[n] << "\n";
}