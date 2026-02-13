#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj(n, 0);
    // since n<=18, we can store adj.list using bitmasks
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a] |= (1<<b);
        adj[b] |= (1<<a);
    }

    // precompute cliques
    vector<int> dp(1<<n, n);
    for (int s=1; s<(1<<n); s++) {
        bool clique = true;
        for (int x=0; x<n; x++) if (s&(1<<x)) {
            if (((adj[x]|(1<<x))&s) != s) {
                clique = false;
                break;
            }
        }
        if (clique) dp[s] = 1;
    }

    for (int s=1; s<(1<<n); s++) {
        for (int submask=s; submask!=0; submask=(submask-1)&s) {
            int subset = s^submask;
            dp[s] = min(dp[s], dp[subset] + dp[submask]);
        }
    }

    cout << dp[(1<<n)-1] << '\n';
}
