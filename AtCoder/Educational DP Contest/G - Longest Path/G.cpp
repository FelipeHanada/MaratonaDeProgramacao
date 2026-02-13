#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> adj;
vector<int> dp;

int longest_path(int i) {
    if (dp[i] != -1) return dp[i];
    if (adj[i].empty()) return dp[i] = 0;
    for (int neighbor : adj[i]) {
        dp[i] = max(dp[i], longest_path(neighbor));
    }
    dp[i]++;
    return dp[i];
}

int main() {
    cin >> n >> m;

    adj.assign(n, vector<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }

    dp.assign(n, -1);
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, longest_path(i));
    }

    cout << ans << '\n';
}
