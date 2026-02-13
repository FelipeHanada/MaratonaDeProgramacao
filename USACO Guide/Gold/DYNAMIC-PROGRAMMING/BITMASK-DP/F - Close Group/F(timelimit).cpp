#include <bits/stdc++.h>
using namespace std;


/*
This algo. has complexity of O(3^n * n^2)

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = true;
    }

    vector<int> dp(1<<n, n);
    for (int i=0; i<n; i++) dp[1<<i] = 1;

    for (int s=1; s<(1<<n); s++) {
        for (int submask=s; submask!=0; submask=(submask-1)&s) {
            int subset = s ^ submask;

            if (dp[subset] == 1 && dp[submask] == 1) {
                // tries to build big clique

                bool clique = true;
                for (int i=0; i<n && clique; i++) if (subset&(1<<i)) {
                    for (int j=0; j<n && clique; j++) if (submask&(1<<j)) {
                        if (!adj[i][j]) {
                            clique = false;
                        }
                    }
                }

                if (clique) {
                    dp[s] = 1;
                    break; // a big clique is the best
                }
            }
            
            dp[s] = min(dp[s], dp[subset] + dp[submask]);
        }
    }

    cout << dp[(1<<n)-1] << '\n';
}