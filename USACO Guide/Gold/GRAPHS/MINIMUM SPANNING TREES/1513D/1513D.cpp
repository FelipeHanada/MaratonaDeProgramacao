#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 2e5;
int v[MAX_N];
int sorted[MAX_N];

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
        i = find(i);
        j = find(j);
        if (i == j) return false;
        if (rank[j] > rank[i]) swap(i, j);
        parent[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
        return true;
    }
};

void solve() {
    int n, p;
    cin >> n >> p;

    for (int i=0; i<n; i++) {
        cin >> v[i];
        sorted[i] = i;
    }
    sort(sorted, sorted+n, [](const int& a, const int& b) -> bool { return v[a] < v[b]; });

    DSU dsu(n);
    ll mst = 0;
    int edge_count = 0;
    for (int i=0; i<n; i++) {
        int curr = sorted[i];
        if (v[curr] > p) break;

        int g = v[curr];
        for (int j=curr-1; j>=0 && g == v[curr]; j--) {
            g = __gcd(g, v[j]);
            if (g != v[curr]) break;
            if (dsu.union_set(curr, j)) {
                mst += g;
                edge_count++;
            } else {
                break;
            }
        }

        g = v[curr];
        for (int j=curr+1; j<n; j++) {
            g = __gcd(g, v[j]);
            if (g != v[curr]) break;
            if (dsu.union_set(curr, j)) {
                mst += g;
                edge_count++;
            } else {
                break;
            }
        }
    }

    cout << mst + (n-1-edge_count) * (ll)p << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
