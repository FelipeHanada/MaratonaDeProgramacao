#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct Edge {
    int u, v; ll c;
    Edge(int u, int v, ll c) : u(u), v(v), c(c) {}
    bool operator<(const Edge &other) {
        return c < other.c;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i=0; i<n; i++) cin >> c[i];
    vector<Edge> edges(m);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges[i].u = x;
        edges[i].v = y;
        edges[i].c = c[y];
    }
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
