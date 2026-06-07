#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 0);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
    }
};

int main() { _
    int n;
    cin >> n;
    DSU dsu(n);
    vector<pair<int,int>> a;
    while (n--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            for (int i=0; i<a.size(); i++) {
                if (
                    (a[i].first < x && x < a[i].second)
                    || (a[i].first < y && y < a[i].second)
                    || (x < a[i].first && a[i].first < y)
                    || (x < a[i].second && a[i].second < y)
                ) {
                    dsu.merge(i, a.size());
                }
            }
            a.push_back({x, y});
        } else {
            cout << (dsu.find(x-1) == dsu.find(y-1) ? "YES" : "NO") << '\n';
        }
    }
}
