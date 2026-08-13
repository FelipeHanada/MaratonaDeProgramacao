#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.assign(n, -1);
        size.assign(n, 1);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (size[pi] < size[pj]) swap(pi, pj);
        parent[pj] = pi;
        size[pi] += size[pj];
    }
};

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q; cin >> n >> q;
    vector<array<int,3>> edges(n-1);
    for (int i=0; i<n-1; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--; edges[i][2]--;
    }

    DSU dsu(n);
    vector<int> ans(q);
    vector<array<int,3>> query(q);
    for (int i=0; i<q; i++) {
        cin >> query[i][0] >> query[i][1];
        query[i][1]--;
        query[i][2] = i;
    }

    sort(query.begin(), query.end());
    sort(edges.begin(), edges.end());
    while (!query.empty()) {
        auto [k, v, i] = query.back(); query.pop_back();
        while (!edges.empty() && edges.back()[0] >= k) {
            auto [r, a, b] = edges.back(); edges.pop_back();
            dsu.merge(a, b);
        }

        ans[i] = dsu.size[dsu.find(v)];
    }

    for (int i=0; i<q; i++) {
        cout << ans[i] - 1 << '\n';
    }
}
