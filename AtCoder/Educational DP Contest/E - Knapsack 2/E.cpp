#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MAX_V = 1e3*100;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i=0; i<n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<ll> dp(MAX_V+1, INT32_MAX); // dp[i] = minimum weight to make value i
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=MAX_V; j>=value[i]; j--) {
            dp[j] = min(dp[j], dp[j-value[i]] + weight[i]);
        }
    }

    int ans = INT32_MAX;
    while (ans == INT32_MAX)
    for (int i=MAX_V; i>=0 && ans == INT32_MAX; i--) {
        if (dp[i] <= w) ans = i;
    }

    cout << ans << '\n';
}
