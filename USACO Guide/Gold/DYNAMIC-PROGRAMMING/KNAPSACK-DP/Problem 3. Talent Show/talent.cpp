#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    int n, W;
    cin >> n >> W;

    int dp[250001];
    fill_n(dp, 250001, INT32_MAX >> 1);
    dp[0] = 0;
    int w, t;
    for (int i=0; i<n; i++) {
        cin >> w >> t;

        for (int j=250000-t; j>=0; j--) {
            if (dp[j] + w < dp[j+t]) {
                dp[j + t] = min(dp[j + t], dp[j] + w);
            }
        }
    }

    double best = -1;
    for (int i=0; i<=250000; i++) {
        if (dp[i] >= W) {
            best = max(best, (double)i / dp[i]);
        }
    }
    cout << (int)(best * 1000) << '\n';
}
