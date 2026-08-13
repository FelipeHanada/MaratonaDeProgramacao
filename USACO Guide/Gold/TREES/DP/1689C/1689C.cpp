#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
pair<int, int> dfs(int curr, int p) {
    vector<pair<int, int>> children;
    for (int neighbor : adj[curr]) if (neighbor != p) {
        children.push_back(dfs(neighbor, curr));
    }

    if (children.size() == 0) return { 0, 1 };
    if (children.size() == 1) return { children[0].second-1, 1+children[0].second };
    return {
        max(
            children[0].first + children[1].second - 1,
            children[1].first + children[0].second - 1
        ),
        children[0].second + children[1].second + 1
    };
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        adj.assign(n, vector<int>());
        for (int i=0; i<n-1; i++) {
            int x, y; cin >> x >> y; x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout << dfs(0, -1).first << '\n';
    }
}
