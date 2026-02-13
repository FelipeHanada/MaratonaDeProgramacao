#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
    }
    int find(int i) {
        while (parent[i] != -1) i = parent[i];
        return i;
    }
    void set_union(int i, int j) {
        int di = find(i), dj = find(j);
        if (di == dj) return;
        if (rank[di] < rank[dj]) swap(di, dj);
        parent[dj] = di;
        if (rank[di] == rank[dj]) rank[di]++;
    }
};

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int x;
    stack<int> to_add;
    for (int i=0; i<n; i++) {
        cin >> x;
        to_add.push(x - 1);
    }

    DSU dsu(n);
    set<int> vertices;
    stack<bool> ans;
    int comp = 0;
    while (!to_add.empty()) {
        int curr = to_add.top(); to_add.pop();
        vertices.insert(curr);
        comp++;

        for (int neighbor : adj[curr]) {
            if (!vertices.count(neighbor)) continue;

            if (dsu.find(curr) != dsu.find(neighbor))
                comp--;

            dsu.set_union(curr, neighbor);
        }

        ans.push(comp == 1);
    }

    while (!ans.empty()) {
        cout << (ans.top() ? "YES" : "NO") << '\n';
        ans.pop();
    }
}