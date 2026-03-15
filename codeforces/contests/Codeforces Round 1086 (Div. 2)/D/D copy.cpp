#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<vector<int>> adj(n);
    vector<vector<int>> inv_adj(n);

    bool ok = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i][i] != '1') ok = 0;
        for (int j=0; j<n; j++) if (j!=i && a[i][j] == '1') {
            adj[i].push_back(j);
            inv_adj[j].push_back(i);
        }
    }
    if (!ok) {
        cout << "No\n";
        return;
    }

    // check for cycles
    vector<bool> in_stk(n, 0);
    stack<pair<int, int>> dfs;
    vector<bool> seen(n, 0);
    bool cycle = 0;
    for (int i=0; i<n && !cycle; i++) if (!seen[i]) {
        dfs.push({i, 1});

        while (!dfs.empty() && !cycle) {
            auto [curr, state] = dfs.top(); dfs.pop();

            if (state) {
                if (seen[curr]) continue;
                dfs.push({curr, 0});
                in_stk[curr] = 1;
                seen[curr] = 1;
                for (int neighbor : adj[curr]) {
                    if (in_stk[neighbor]) {
                        cycle = 1;
                        break;
                    }
                    if (seen[neighbor]) continue;
                    dfs.push({neighbor, 1});
                }
            } else {
                in_stk[curr] = 0;
            }
        }
    }

    if (cycle) {
        cout << "No\n";
        return;
    }

    vector<int> level(n, -1);
    vector<int> size(n);
    vector<int> out_deg(n);
    queue<int> q;
    for (int i=0; i<n; i++) {
        out_deg[i] = adj[i].size();
        if (out_deg[i] == 0) {
            q.push(i);
            level[i] = 0;
        }
    }

    vector<pair<int,int>> ans;
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        size[curr] = 1;
        for (int neighbor : adj[curr]) {
            size[curr] += size[neighbor];

            if (level[neighbor] == level[curr] - 1) {
                ans.push_back({curr, neighbor});
            }
        }
        for (int p : inv_adj[curr]) {
            if (!(--out_deg[p])) {
                level[p] = level[curr] + 1;
                q.push(p);
            }
        }
    }

    if (ans.size() != n-1) {
        cout << "No\n";
        return;
    }

    for (int i=0; i<n; i++) {
        if (adj[i].size() + 1 != size[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (auto [p, q] : ans) {
        cout << p+1 << ' ' << q+1 << '\n';
    }
}


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}