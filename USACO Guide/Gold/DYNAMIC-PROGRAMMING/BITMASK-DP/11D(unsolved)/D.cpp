#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<ll>> dp(1<<n, vector<ll>(n));
    // dp[S][x] = number of paths with vertices S ending in x

    for (int i=0; i<n; i++) dp[0][i] = 1;
    ll ans = 0;
    for (int s=0; s<(1<<n); s++) { // push DP version
        for (int x=0; x<n; x++) if (s&(1<<x)) {
            for (int y : adj[x]) if (!(s&(1<<y))) {
                dp[s|y][y] += dp[s][x];
            }

            if (__builtin_popcount(s) >= 3 && adj[]) {
                
            }
        }
    }
}