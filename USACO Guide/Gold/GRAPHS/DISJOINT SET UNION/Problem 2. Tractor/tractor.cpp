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

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n;
int node(int i, int j) { return i*n+j; }

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<array<int,3>> edges;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<4; k++) {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii < 0 || ii >= n || jj < 0 || jj >= n) continue;
                if (make_tuple(grid[i][j], i, j) < make_tuple(grid[ii][jj], ii, jj)) continue;
                edges.push_back({ grid[i][j] - grid[ii][jj], node(i, j), node(ii, jj) });
            }
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n*n);
    for (auto [ w, u, v ] : edges) {
        dsu.merge(u, v);
        if (dsu.size[dsu.find(u)] >= n*n/2) {
            cout << w << '\n';
            break;
        }
    }
}
