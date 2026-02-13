#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d(n);
    d[0] = 0;
    stack<pair<int, int>> dfs;
    dfs.push({0, 0});
    while (!dfs.empty()) {
        auto [curr, dist] = dfs.top();
        for (int neighbor : adj[curr]) {
            if (neighbor == curr) continue;
            d[neighbor] = dist + 1;
            dfs.push({neighbor, dist + 1});
        }
    }

    

    for (int i=0; i<n; i++) {

    }
}