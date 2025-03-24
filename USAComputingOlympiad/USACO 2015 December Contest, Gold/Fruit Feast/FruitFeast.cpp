#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_T = 5000000;
bool dp[MAX_T + 1];
bool dp2[MAX_T + 1];

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b;
    cin >> t >> a >> b;

    tie(a, b) = make_tuple(min(a, b), max(a, b));

    fill_n(dp, t + 1, false);
    fill_n(dp2, t + 1, false);
    dp[0] = dp2[0] = true;
    for (int i=a; i<b; i++) {
        if (dp[i - a]) {
            dp[i] = dp2[i/2] = true;
        }
    }
    for (int i=b; i<=t; i++) {
        if (dp[i - a] || dp[i - b]) {
            dp[i] = dp2[i/2] = true;
        }
    }

    int ans = 0;
    for (int i=a; i<b; i++) {
        if (dp2[i - a]) {
            dp2[i] = true;
            ans = i;
        }
    }
    for (int i=b; i<=t; i++) {
        if (dp2[i - a] || dp2[i - b]) {
            dp2[i] = true;
            ans = i;
        }
    }

    cout << ans << "\n";
}