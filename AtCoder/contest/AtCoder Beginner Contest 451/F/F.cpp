#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;


struct DSU {
    vector<int> parent;
    vector<int> rank;
    vector<array<int,2>> color;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 0);
        color.assign(n, array<int,2>({0, 1}));
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

        color[pi][0] += color[pj][1];
        color[pi][1] += color[pj][0];

        return 1;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    int ans = 0;
    vector<int> bip(n, -1);
    while (q--) {
        int x, y;
        cin >> x >> y;

        if (dsu.union_set(x, y)) {

        } else {
            if (bip[i] )
        }
    }
}
