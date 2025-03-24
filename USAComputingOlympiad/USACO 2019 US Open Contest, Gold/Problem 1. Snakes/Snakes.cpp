#include <bits/stdc++.h>
using namespace std;


constexpr int MAXK = 399;
int dp0[MAXK+1][2]; // prev state
int dp1[MAXK+1][2]; // curr state

/*
dp[i][0] = current minimum sum of net sizes after i net changes
dp[i][1] = current net size of this solution
*/ 


int main() {
    // freopen("snakes.in", "r", stdin);
    // freopen("snakes.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    for (int i=0; i<=k; i++) dp0[i][0] = INT32_MAX;
    int ai; cin >> ai;
    int s = ai;
    dp0[0][0] = dp0[0][1] = dp1[0][1] = ai;

    for (int i=1; i<n; i++) {
        cin >> ai;
        s += ai;

        dp1[0][0] = dp0[0][0] + dp0[0][1];
        for (int j=1; j<=k; j++) {
            if (j > i) continue;

            if (dp0[j][1] < ai || dp0[j-1][0] + ai < dp0[j][0] + dp0[j][1]) {
                dp1[j][0] = dp0[j-1][0] + ai;
                dp1[j][1] = ai;
            } else {
                dp1[j][0] = dp0[j][0] + dp0[j][1];
            }
        }

        if (dp0[k][1] < ai)

        swap(dp0, dp1);
    }

    int ans = INT32_MAX;
    for (int i=0; i<=k; i++) {
        if (dp0[i][0] < s) continue;
        ans = min(ans, dp0[i][0]);
    }

    cout << ans - s << "\n";
}
