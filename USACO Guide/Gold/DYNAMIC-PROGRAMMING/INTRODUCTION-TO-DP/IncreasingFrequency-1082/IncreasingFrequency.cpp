#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, c; cin >> n >> c;

    int a[n];
    int prefix[n + 1] = {0};  // qt of already good numbers;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + ((a[i] == c) ? 1 : 0);
    }

    tuple<int, int, int> dp[n + 1];
    // cost / start / k
    fill_n(dp, n, make_tuple(INT32_MIN, 0, 0));
    dp[0] = {0, 0, 0};
    // dp[i] for the best segment that starts in some j and ends in i;

    for (int i=0; i<n; i++) {
        int cost = get<0>(dp[i]);
        if (a[i] == get<1>(dp[i])) cost++;
        if (a[i] == c) cost--;

        if (cost > 1) {
            // including i + 1 element in the best segment ending in i
            dp[i + 1] = {cost, get<1>(dp[i]), get<2>(dp[i])};
        } else {
            // i + 1 as the start of a new segment
            dp[i + 1] = {((a[i] == c) ? 0 : 1), i, a[i]};
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        int start = get<1>(dp[i + 1]);
        int left = prefix[start];
        int cost = get<0>(dp[i + 1]);
        int right = prefix[n] - prefix[i + 1];

        ans = max(ans, left + cost + right);
    }

    cout << ans << endl;
}
