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
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int A, B, n, m;
    cin >> A >> B >> n >> m;

    vector<int> vert(n), hor(m);
    vert.push_back(0); vert.push_back(A);
    hor.push_back(0); hor.push_back(B);
    for (int i=0; i<n; i++) {
        cin >> vert[i];
    }
    for (int i=0; i<m; i++) {
        cin >> hor[i];
    }
    sort(vert.begin(), vert.end());
    sort(hor.begin(), hor.end());

    vector<tuple<int, int, int>> edges;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {

            if (i < n) {
                edges.push_back(make_tuple(hor[j+1] - hor[j], 2001*j+i, 2001*j + (i+1)));
            }

            if (j < m) {
                edges.push_back(make_tuple(vert[i+1] - vert[i], 2001*j+i, 2001*(j+1) + i));
            }

        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(2001*2001);
    ll ans = 0;
    int c = 0;
    for (auto [cost, a, b] : edges) {
        if (dsu.union_set(a, b)) {
            ans += cost;
            c++;
        }
    }

    cout << ans << '\n';
}
