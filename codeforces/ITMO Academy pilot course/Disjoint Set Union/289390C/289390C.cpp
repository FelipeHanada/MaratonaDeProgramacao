#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;
    vector<int> exp;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 1);
        exp.assign(n, 0);
    }
    pair<int, int> find(int i) {
        int ans = exp[i];
        while (parent[i] != -1) {
            i = parent[i];
            ans += exp[i];
        }
        return make_pair(i, ans);
    }
    void union_set(int i, int j) {
        auto [pi, _] = find(i);
        auto [pj, __] = find(j);
        if (pi == pj) return;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        exp[pj] -= exp[pi];
        if (rank[pi] == rank[pj]) rank[pi]++;
    }
    void add(int i, int v) {
        auto [pi, _] = find(i);
        exp[pi] += v;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        string op;
        cin >> op;
        if (op == "add") {
            int x, v;
            cin >> x >> v;
            x--;
            dsu.add(x, v);
        } else if (op == "join") {
            int x, y;
            cin >> x >> y;
            x--; y--;
            dsu.union_set(x, y);
        } else {
            int x;
            cin >> x;
            x--;
            auto [_, v] = dsu.find(x);
            cout << v << '\n';
        }
    }
}