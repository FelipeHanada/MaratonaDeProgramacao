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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
    }
    vector<array<int,3>> ops(k);
    for (int i=0; i<k; i++) {
        string op;
        cin >> op >> ops[i][1] >> ops[i][2];
        ops[i][0] = (op == "ask");
        ops[i][1]--;
        ops[i][2]--;
    }
    reverse(ops.begin(), ops.end());

    vector<bool> ans;
    DSU dsu(n);
    for (auto [op, x, y] : ops) {
        if (op) {
            // ask
            ans.push_back(dsu.find(x) == dsu.find(y));
        } else {
            dsu.union_set(x, y);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}