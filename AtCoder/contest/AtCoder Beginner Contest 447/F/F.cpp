#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;



int n;
vector<vector<int>> adj;

void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    vector<bool> seen(n, 0);
    vector<int> deg(n);
    for (int i=0; i<n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1) {
            q.push(i);
            seen[i] = 1;
        }
    }

    int ans = 1;
    vector<int> dp(n, 0);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        if (adj[curr].size() >= 3) {
            // pode começar um caminho
            dp[curr] = 1;
            for (int x : adj[curr]) if (seen[x]) {
                // e terminar um
                ans = max(ans, 1 + dp[x]);
            }
        }

        if (adj[curr].size() >= 4) {
            // pode incrementar um caminho
            int big1 = 0, big2 = 0;
            for (int x : adj[curr]) if (seen[x]) {
                dp[curr] = max(dp[curr], dp[x] + 1);

                if (dp[x] > big1) {
                    tie(big1, big2) = make_tuple(dp[x], big1);
                } else if (dp[x] > big2) {
                    big2 = dp[x];
                }
            }

            ans = max(ans, big1 + big2 + 1);
        }

        for (int x : adj[curr]) if (!seen[x]) {
            if (--deg[x] == 1) {
                q.push(x);
                seen[x] = 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) solve();
}
