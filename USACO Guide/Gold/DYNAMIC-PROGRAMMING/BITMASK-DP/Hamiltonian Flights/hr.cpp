/*
let v be a vertex of G = (V, E)
we want to count the number of Hamiltonian paths of G, starting on v=1
to do that we run a bitmask dp

let dp(S, x) be the number of partial Hamiltonian paths (Hamiltonian on the graph G[S])
    with all the vertices in S ending on vertex x (x in S by definition)
    dp(S, x) = 1    if S = {v} and x = v
               0    otherwise

we can easily compute dp(S, x) based on dp(S-{x}, y) for all y in V
    dp(S, x) = sum(dp(S-{x}, y) * (yx in E ? 1 : 0)) for all y in V

the answer is dp(V, n)
*/

#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }

    vector<vector<int>> dp(n, vector<int>(1<<n, 0));
    dp[0][1] = 1;
    for (int s=3; s<(1<<n); s += 2) {
        // we do not need to consider subsets without 1
        for (int y=0; y<n; y++) if (s&(1<<y)) {
            for (int x : adj[y]) if (s&(1<<x)) {
                dp[x][s] = (dp[x][s] + dp[y][s^(1<<x)]) % MOD;
            }
        }
    }

    cout << dp[n-1][(1<<n)-1] << '\n';
}
