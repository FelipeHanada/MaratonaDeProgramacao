#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent;
    vector<int> size;
    vector<int> minn;
    vector<int> maxx;
    DSU(int n) {
        parent.assign(n, -1);
        size.assign(n, 1);
        minn.resize(n);
        maxx.resize(n);
        iota(minn.begin(), minn.end(), 0);
        iota(maxx.begin(), maxx.end(), 0);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (size[pi] < size[pj]) swap(pi, pj);
        parent[pj] = pi;
        size[pi] += size[pj];
        minn[pi] = min(minn[pi], minn[pj]);
        maxx[pi] = max(maxx[pi], maxx[pj]);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        string op;
        cin >> op;
        if (op == "union") {
            int x, y;
            cin >> x >> y;
            x--; y--;
            dsu.union_set(x, y);
        } else {
            int x;
            cin >> x;
            x--;
            x = dsu.find(x);
            cout << dsu.minn[x] + 1 << ' ' << dsu.maxx[x] + 1 << ' ' << dsu.size[x] << '\n';
        }
    }
}