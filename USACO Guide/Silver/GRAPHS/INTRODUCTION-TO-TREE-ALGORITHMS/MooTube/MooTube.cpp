#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 5000;
int weights[MAX_N][MAX_N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[a][b] = weights[b][a] = w;
    }

    for (int i=0; i<q; i++) {
        int k, v; cin >> k >> v;
        v--;

        stack<pair<int, int>> dfs; dfs.emplace(make_pair(v, -1));
        int ans = 0;
        while (dfs.size() > 0) {
            auto curr = dfs.top(); dfs.pop();
            ans++;

            for (int x : adj[curr.first]) {
                if (x == curr.second) continue;

                if (weights[curr.first][x] >= k)
                    dfs.emplace(make_pair(x, curr.first));
            }
        }

        cout << ans - 1 << endl;
    }
}