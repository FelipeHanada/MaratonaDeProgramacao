#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent;
    vector<int> rank;
    int n;
    DSU(int n) {
        this->n = n;
        this->parent = vector<int>(n, -1);
        this->rank = vector<int>(n, 1);
    }
    int find(int i) {
        while (parent[i] >= 0)
            i = parent[i];
        return i;
    }
    bool union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return false;

        if (rank[pi] < rank[pj]) swap(pi, pj);
        // makes pi parent of pj
        parent[pj] = pi;
        if (rank[pi] == rank[pj])
            rank[pi]++;
        return true;
    }
};


int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges(e);
    for (int i=0; i<e; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    int q, x;
    cin >> q;
    stack<int> to_restore;
    vector<bool> removed(e, false);
    for (int i=0; i<q; i++) {
        cin >> x;
        removed[x-1] = true;
        to_restore.push(x-1);
    }

    DSU dsu(n);
    int w = n;
    for (int i=0; i<e; i++) {
        if (removed[i]) continue;
        if (dsu.union_set(edges[i].first, edges[i].second))
            w--;
    }

    stack<int> ans;
    while (!to_restore.empty()) {
        ans.push(w);
        int curr = to_restore.top();
        if (dsu.union_set(edges[curr].first, edges[curr].second))
            w--;
        to_restore.pop();
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
}
