#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }
    int find(int i) {
        while (parent[i] != -1) i = parent[i];
        return i;
    }
    bool union_set(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return false;
        if (rank[i] < rank[j]) swap(i, j);
        parent[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    vector<tuple<int, int, int>> edges;
    int x;
    bool valid = true;
    for (int i=0; i<n; i++) {
        cin >> x;
        dist[i][0] = x;
        for (int j=1; j<=i; j++) {
            cin >> x;
            dist[i][j] = x;
        }
        for (int j=i+1; j<n; j++) {
            cin >> x;
            dist[i][j] = x;
            if (x > 0)
                edges.push_back(make_tuple(x, i, j));
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int edge_count = 0;
    vector<vector<pair<int, int>>> tree(n);
    // since all edges are weight positive
    // all minimum distance edges are single edges
    // we can build a tree using Kruskal algo
    for (auto [c, a, b] : edges) {
        if (dsu.union_set(a, b)) {
            tree[a].push_back(make_pair(c, b));
            tree[b].push_back(make_pair(c, a));
            edge_count++;
        }
    }

    if (edge_count < n-1) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> dist_tree(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        // running single source distance for every vertex

        vector<bool> seen(n, false);
        stack<pair<int, int>> dfs;
        dist_tree[i][i] = 0;
        dfs.push(make_pair(0, i));
        seen[i] = true;

        while (!dfs.empty()) {
            auto [d, curr] = dfs.top(); dfs.pop();

            for (auto [c, neighbor] : tree[curr]) {
                if (seen[neighbor]) continue;
                dist_tree[i][neighbor] = d + c;
                dfs.push(make_pair(d + c, neighbor));
                seen[neighbor] = true;
            }
        }
    }
    

    for (int i=0; i<n && valid; i++) {
        for (int j=0; j<n; j++) {
            if (dist[i][j] != dist_tree[i][j]) {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
