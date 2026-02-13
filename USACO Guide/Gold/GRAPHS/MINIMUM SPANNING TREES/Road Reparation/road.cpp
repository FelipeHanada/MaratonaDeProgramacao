#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 1);        
    }
    int find(int i) {
        while (parent[i] != -1) {
            i = parent[i];
        }
        return i;
    }
    bool union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return false;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edge(m);
    for (int i=0; i<m; i++) {
        cin >> get<1>(edge[i]) >> get<2>(edge[i]) >> get<0>(edge[i]);
    }
    sort(edge.begin(), edge.end());

    DSU dsu(n+1);
    ll cost = 0;
    int edge_count = 0;
    for (auto [c, a, b] : edge) {
        if (dsu.union_set(a, b)) {
            cost += c;
            edge_count++;
        }
    }

    if (edge_count < n-1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cost << '\n';
    }
}