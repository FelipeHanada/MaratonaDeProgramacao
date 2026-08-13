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
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        string op; int x, y;
        cin >> op >> x >> y; x--; y--;
        if (op == "union") {
            dsu.union_set(x, y);
        } else {
            cout << ((dsu.find(x) == dsu.find(y)) ? "YES" : "NO") << '\n';
        }
    }
}