#include <bits/stdc++.h>
using namespace std;

constexpr int md = int(1e9) + 7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    vector<int> in_deg(n, 0);
    queue<int> q; q.push(0);
    vector<bool> seen(n, 0); seen[0] = 1;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int j : adj[i]) {
            in_deg[j]++;
            if (!seen[j]) {
                seen[j] = 1;
                q.push(j);
            }
        }
    }

    vector<int> dp(n, 0); dp[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int j : adj[i]) {
            dp[j] = add(dp[j], dp[i]);
            if (!(--in_deg[j])) q.push(j);
        }
    }

    cout << dp[n-1] << '\n';
}