#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    int n, W;
    cin >> n >> W;

    map<int, int> dp, nextDp;
    dp[0] = 0;
    int w, t;
    for (int i=0; i<n; i++) {
        cin >> w >> t;

        for (auto &[dpW, dpT] : dp) {
            nextDp[dpW] = max(nextDp[dpW], dpT);

            if (dpW < W) {
                nextDp[dpW + w] = max(nextDp[dpW + w], dpT + t);
            } else {
                if ((double)t / w > (double)dp[dpW] / dpW) {
                    nextDp[dpW + w] = max(nextDp[dpW + w], dpT + t);
                }
            }
        }

        swap(dp, nextDp);
    }

    double best = -1;
    for (auto it = dp.rbegin(); it != dp.rend(); it++) {
        if (it->first < W) break;
        best = max(best, (double)it->second / it->first);
    }

    cout << (int)(best * 1000) << '\n';
}
