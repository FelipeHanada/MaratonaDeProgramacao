#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent = vector<int>(n, -1);
        size = vector<int>(n, 1);
    }
    int find(int i) {
        while (parent[i] != -1) i = parent[i];
        return i;
    }
    bool set_union(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return false;
        if (size[pi] < size[pj]) swap(pi, pj);
        parent[pj] = pi;
        size[pi] += size[pj];
        return true;
    }
};

int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    DSU dsu(n);
    int big = 1, comp = n;
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        a = dsu.find(a-1);
        b = dsu.find(b-1);
        if (dsu.set_union(a, b)) comp--;
        big = max(big, max(dsu.size[a], dsu.size[b]));

        cout << comp << ' ' << big << '\n';
    }
}
