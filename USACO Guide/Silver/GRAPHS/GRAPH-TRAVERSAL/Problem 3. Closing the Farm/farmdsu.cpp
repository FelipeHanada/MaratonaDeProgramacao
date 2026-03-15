#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> rank;
    vector<int> parent;
    DSU(int n) {
        rank.assign(n, 0);
        parent.assign(n, -1);
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
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }
    reverse(a.begin(), a.end());

    vector<bool> ans(n);
    set<int> s;
    DSU dsu(n);
    int comps = 0;
    for (int i=0; i<n; i++) {
        comps++;
        for (int neighbor : adj[a[i]]) {
            if (s.count(neighbor)) {
                comps -= dsu.union_set(a[i], neighbor);
            }
        }
        s.insert(a[i]);

        ans[i] = comps < 2;
    }

    reverse(ans.begin(), ans.end());
    for (bool x : ans) {
        cout << (x ? "YES" : "NO") << '\n';
    }
}
