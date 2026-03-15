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

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (j != i) {
            for (int k=0; k<n; k++) if (k != i && k != j) {
                if (a[i][j] == '1' && a[j][k] == '1') {
                    ok = ok && (a[i][k] == '1');
                }
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
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

    vector<int> ans(n, -1);
    int r;
    for (int i=0; i<n; i++) {
        if (inv_adj[i].size() == 0) {
            r = i;
            break;
        }
    }

    queue<int> bfs;
    bfs.push(r);
    seen.assign(n, 0); seen[r] = 1;
    while (!bfs.empty()) {
        auto curr = bfs.front(); bfs.pop();
        
        for (int neighbor : adj[curr]) {
            ans[neighbor] = curr;
            if (!seen[neighbor]) {
                seen[neighbor] = 1;
                bfs.push(neighbor);
            }
        }
    }

    if (count(seen.begin(), seen.end(), 0)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i=0; i<n; i++) {
        if (ans[i] != -1) {
            cout << ans[i] + 1 << ' ' << i + 1 << '\n';
        }
    }
}


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}