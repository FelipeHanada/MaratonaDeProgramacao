#include <bits/stdc++.h>
using namespace std;



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
    void union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i=1; i<n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> prev(2*n);
    vector<int> next(2*n, -1);
    for (int i=1; i<n; i++) {
        if (a[i] + i < n) {
            next[i] = n+a[i]+i;
            prev[n+a[i]+i].push_back(i);
        }
    }
    for (int i=1; i<n; i++) {
        if (i-a[i] >= 0) {
            next[n+i] = i-a[i];
            prev[i-a[i]].push_back(n+i);
        }
    }

    vector<ll> dp(2*n, -1);
    queue<int> q;
    for (int i=1; i<2*n; i++) {
        if (next[i] == -1) {
            q.push(i);
            dp[i] = a[i % n];
        }
    }

    DSU dsu(2*n);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        for (int p : prev[curr]) {
            dsu.union_set(curr, p);
            dp[p] = dp[curr] + a[p % n];
            q.push(p);
        }
    }

    for (int i=1; i<n; i++) {
        if (dp[n+i] == -1 || dsu.find(0) == dsu.find(n+i)) {
            cout << "-1\n";
        } else {
            cout << i + dp[n+i] << '\n';
        }
    }
}