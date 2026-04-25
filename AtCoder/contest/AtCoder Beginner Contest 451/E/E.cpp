#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;



struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 0);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    bool union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return 0;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
        return 1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> dist(n, vector<ll>(n));
    vector<array<ll,3>> a;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            cin >> dist[i][j];
            dist[j][i] = dist[i][j];
            a.push_back(array<ll,3>({dist[i][j], i, j}));
        }
    }

    sort(a.begin(), a.end());
    DSU dsu(n);
    vector<vector<pair<ll,ll>>> adj(n);
    int edges = 0;

    for (auto [d, x, y] : a) {
        if (dsu.union_set(x, y)) {
            adj[x].push_back({y, d});
            adj[y].push_back({x, d});
            edges++;
        }
    }

    // vector<deque<pair<ll,ll>>> min_dist(n);
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) if (j != i) {
    //         min_dist[i].push_back({dist[i][j], j});
    //     }
    //     sort(min_dist[i].begin(), min_dist[i].end());

    //     for (auto [d, j] : min_dist[i]) {
    //         if (dsu.union_set(i, j)) {
    //             adj[i].push_back({j, d});
    //             adj[j].push_back({i, d});
    //             edges++;
    //             break;
    //         }
    //     }
    // }

    if (edges != n - 1) {
        cout << "No\n";
        return 0;
    }

    vector<vector<ll>> dist_t(n, vector<ll>(n));
    for (int i=0; i<n; i++) {
        dist_t[i][i] = 0;
        stack<int> dfs; dfs.push(i);
        vector<bool> seen(n, 0); seen[i] = 1;

        while (!dfs.empty()) {
            auto curr = dfs.top(); dfs.pop();

            for (auto [neighbor, d] : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                dist_t[i][neighbor] = dist_t[i][curr] + d;
                dfs.push(neighbor);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (j != i) {
            if (dist[i][j] != dist_t[i][j]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}