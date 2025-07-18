#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    for (int i=1; i<n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    vector<int> likes(n);
    for (int i=0; i<n; i++) {
        cin >> likes[i];
    }

    vector<int> dp; dp.push_back(0);
    // best paths with size i that ends on node dp[i]

    vector<bool> seen(n, false);
    stack<pair<int, int>> dfs; dfs.push({0, 0});
    while (!dfs.empty()) {
        auto curr = dfs.top(); dfs.pop();
        seen[curr.first] = true;

        for (auto prox : adj[curr.first]) {
            if (seen[prox]) continue;
            dfs.push({prox, curr.second + 1});
        }
    }
}