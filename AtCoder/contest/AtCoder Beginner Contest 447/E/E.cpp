#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;


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

constexpr int md = 998244353;
int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}

int main() { _
    int n, m;
    cin >> n >> m;
    vector<array<int,2>> edges(m);
    for (int i=0; i<m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }

    DSU dsu(n);
    int comps = n;
    int i=m-1;
    while (comps > 2 || dsu.find(edges[i][0]) == dsu.find(edges[i][1])) {
        comps -= dsu.union_set(edges[i][0], edges[i][1]);
        i--;
    }

    vector<int> w(m);
    w[0] = 2;
    for (int i=1; i<m; i++) {
        w[i] = (w[i-1]<<1) % md;
    }

    int ans = 0;
    for (int j=0; j<=i; j++) {
        // testa cada aresta
        if (dsu.find(edges[j][0]) != dsu.find(edges[j][1])) {
            ans = add(ans, w[j]);
        }
    }

    cout << ans << '\n';
}
