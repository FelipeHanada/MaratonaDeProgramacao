#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    stack<pair<int, int>> dfs; dfs.push({ 0, -1 });
    vector<int> deg(n, 0);
    vector<int> parent(n);
    queue<int> q;
    while (!dfs.empty()) {
        auto [curr, p] = dfs.top(); dfs.pop();
        parent[curr] = p;
        for (int neighbor : adj[curr]) if (neighbor != p) {
            deg[curr]++;
            dfs.push({ neighbor, curr });
        }
        if (deg[curr] == 0) q.push(curr);
    }

    vector<int> dp1(n), dp2(n);
    // dp1[i] = max matching on that subtree s.t. the root is not taken by any edge
    // dp2[i] = ... s.t. the root IS taken by some edge
    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        dp1[curr] = dp2[curr] = 0;
        int poor = INT32_MAX;
        for (int neighbor : adj[curr]) if (neighbor != parent[curr]) {
            dp1[curr] += max(dp1[neighbor], dp2[neighbor]);
            dp2[curr] += max(dp1[neighbor], dp2[neighbor]);
            if (dp2[neighbor] >= dp1[neighbor]) poor = INT32_MIN;
            poor = min(poor, dp2[neighbor] - dp1[neighbor]);

            if (!(--deg[neighbor])) q.push(neighbor);
        }

        if (poor != INT32_MAX) {
            if (poor == INT32_MIN) dp2[curr]++;
            else dp2[curr] += poor + 1;
        }
    }

    cout << max(dp1[0], dp2[0]) << '\n';
}
