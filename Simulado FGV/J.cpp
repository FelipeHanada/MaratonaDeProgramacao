#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, T;
    cin >> n >> T;

    vector<int> h(n), d(n);
    vector<int> times;
    map<int, vector<int>> points;
    map<int, int> dp;
    points[T] = vector<int>();
    for (int i=0; i<n; i++) {
        int hi, di, ti;
        cin >> hi >> di >> ti;
        h[i] = hi;
        d[i] = di;
        for (int j=0; j<ti; j++) {
            int t;
            cin >> t;
            times.push_back(t);
            points[t].push_back(i);
        }
    }
    sort(times.begin(), times.end());

    int ans = INT32_MIN;
    dp[0] = 0;
    for (auto [t, choices] : points) {
        for (int choice : choices) {
            int nt = t + d[choice];
            if (nt > T) continue;
            auto lb = lower_bound(times.begin(), times.end(), nt);
            dp[*lb] = max(dp[*lb], dp[t] + h[choice]);
            ans = max(ans, dp[*lb]);
        }
    }

    cout << ans << '\n';
}