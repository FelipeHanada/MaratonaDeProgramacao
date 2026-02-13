#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }
    int find(int i) {
        while (parent[i] != -1)
            i = parent[i];

        return i;
    }
    void set_union(int i, int j) {
        int pi = find(i),
            pj = find(j);
        if (pi == pj) return;

        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
    }
};

int n, q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    DSU dsu(n);
    int t, u, v;
    for (int i=0; i<q; i++) {
        cin >> t >> u >> v;
        if (t == 0) {
            dsu.set_union(u, v);
        } else {
            cout << ((dsu.find(u) == dsu.find(v)) ? 1 : 0) << '\n';
        }
    }
}
