#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);


void solve() {
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

    int w;
    cin >> w;
    vector<string> h(n);
    for (int i=0; i<n; i++) cin >> h[i];

    vector<set<int>> adj2(n);
    for (int i=0; i<n; i++) if (h[i][0] == 'o') {
        queue<pair<int, int>> q;
        q.push({i, 0});
        while (!q.empty() && q.front().second + 1 < w) {
            auto [curr, dist] = q.front(); q.pop();

            if (h[curr][dist+1] == 'o') q.push({curr, dist+1});
            for (int neighbor : adj[curr]) if (h[neighbor][dist+1] == 'o') {
                q.push({neighbor, dist+1});
            }
        }

        while (!q.empty() && q.front().second + 1 == w) {
            auto [curr, dist] = q.front(); q.pop();

            if (h[curr][0] == 'o') q.push({curr, dist + 1});
            for (int neighbor : adj[curr]) if (h[neighbor][0] == 'o') {
                q.push({neighbor, dist + 1});
            }
        }

        while (!q.empty()) {
            auto [curr, __] = q.front(); q.pop();
            adj2[i].insert(curr);
        }
    }

    // check loops in adj2
    bool ok = 0;
    vector<bool> seen(n, 0);
    for (int i=0; i<n; i++) if (!seen[i]) {
        stack<int> stk;
        stk.push(i);
        seen[i] = 1;

        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();

            for (int neighbor : adj2[curr]) {
                if (seen[neighbor]) ok = 1;
                else {
                    seen[neighbor] = 1;
                    stk.push(neighbor);
                }
            }
        }
    }

    cout << (ok ? "Yes" : "No") << '\n';
}


int main() { _
    int tt;
    cin >> tt;
    while (tt--) solve();
}
