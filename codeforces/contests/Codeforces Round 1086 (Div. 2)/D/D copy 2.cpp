#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<vector<bool>> adjm(n, vector<bool>(n,0));

    bool ok = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i][i] != '1') ok = 0;
        for (int j=0; j<n; j++) if (j!=i && a[i][j] == '1') {
            adjm[i][j] = 1;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (adjm[i][j] && adjm[j][k]) {
                    ok = ok && adjm[i][k];
                }
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    vector<vector<int>> adj(n);
    vector<pair<int,int>> ans;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (i != j && adjm[i][j]) {
            bool add = 1;
            for (int k=0; k<n; k++) if (k != i && k != j && adjm[i][k] && adjm[k][j]) {
                add = 0;
            }

            if (add) {
                ans.push_back({i, j});
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // check for conn
    stack<int> dfs;
    vector<bool> seen(n, 0);
    dfs.push(0); seen[0] = 1;
    while (!dfs.empty()) {
        auto curr = dfs.top(); dfs.pop();
        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = 1;
            dfs.push(neighbor);
        }
    }

    if (count(seen.begin(), seen.end(), false)) {
        cout << "NO\n";
        return;
    }

    if (ans.size() < n-1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto [p, q] : ans) {
        cout << p+1 << ' ' << q+1 << '\n';
    }
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}