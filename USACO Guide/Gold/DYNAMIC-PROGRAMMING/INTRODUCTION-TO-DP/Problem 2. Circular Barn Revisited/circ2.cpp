#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    deque<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    auto solve = [&]() -> ll {
        // needs to place k-1 doors
        // the first door is in index 0

        vector<vector<ll>> dp(k, vector<ll>(n, INT64_MAX));
        // dp[kk][last] = minimum distance walked with kk + 1 doors opened
        //                      s.t. the last door was opened at 0

        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int kk = k-1; kk >= 0; kk--) {
                for (int last = 0; last < i; last++) {
                    if (dp[kk][last] != INT64_MAX)
                        dp[kk][last] += a[i] * (i - last);

                    // opening at this point
                    if (kk && dp[kk-1][last] != INT64_MAX)
                        dp[kk][i] = min(dp[kk][i], dp[kk-1][last]);
                }
            }
        }

        ll ans = INT64_MAX;
        for (int i=0; i<n; i++) ans = min(ans, dp[k-1][i]);
        return ans;
    };

    ll ans = INT64_MAX;
    for (int i=0; i<n; i++) {
        ans = min(ans, solve());
        a.push_back(a.front());
        a.pop_front();
    }

    cout << ans << '\n';
}

/*
dp[k][i] = minimum distance the cows walk with k doors opened
                s.t. the last door open is in index i

dp[k][i] = min(
    dp[k][j < i] para cada porta aberta antes de i
    dp[k-1][j < i] para cada porta aberta antes de i
)

*/