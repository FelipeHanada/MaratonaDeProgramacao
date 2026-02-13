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
        while (parent[i] != -1) i = parent[i];
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
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> teams(n);
    vector<tuple<int, int, int>> edges;
    for (int i=0; i<n; i++) {
        cin >> teams[i];
        for (int j=0; j<i; j++) {
            edges.push_back(make_tuple(teams[i] ^ teams[j], i , j));
        }
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n+1);
    ll ans = 0;
    for (auto it = edges.rbegin(); it != edges.rend(); it++) {
        // run Kruskal
        auto [points, a, b] = *it;
        if (dsu.union_set(a, b)) {
            ans += points;
        }
    }

    cout << ans << '\n';
}
