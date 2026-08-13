#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    vector<pair<int, int>> dp(n, { -1, -1 });
    vector<int> in_deg(n, 0);
    vector<bool> seen(n, 0); seen[0] = 1;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        dp[i] = { 1, -1 };
        for (int j : adj[i]) {
            in_deg[j]++;
            if (seen[j]) continue;
            seen[j] = 1;
            q.push(j);
        }
    }

    q.push(0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int j : adj[i]) {
            dp[j] = max(dp[j], { dp[i].first + 1, i });
            if (!(--in_deg[j])) q.push(j);
        }
    }

    if (dp[n-1].first == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    pair<int, int> curr = dp[n-1];
    int last = n-1;

    cout << curr.first << '\n';
    vector<int> ans;
    while (last != -1) {
        ans.push_back(last);
        last = dp[last].second;
    }
    for (int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}