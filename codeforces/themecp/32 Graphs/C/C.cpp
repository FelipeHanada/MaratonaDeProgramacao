#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int main() { _
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<array<int,2>> b(n);
    for (int i=0; i<n; i++) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    bool ok = 1;
    for (int i=0; ok && i<n; i++) {
        auto [c, curr] = b[i];
        set<int> s;
        for (int neighbor : adj[curr]) if (a[neighbor] <= c) {
            s.insert(a[neighbor]);
        }
        if (s.count(c)) ok = 0;
        if (s.size() < c - 1) ok = 0;
    }

    if (ok) {
        for (int i=0; i<n; i++) {
            cout << b[i][1] + 1 << ' ';
        } cout << '\n';
    } else {
        cout << "-1\n";
    }
}
