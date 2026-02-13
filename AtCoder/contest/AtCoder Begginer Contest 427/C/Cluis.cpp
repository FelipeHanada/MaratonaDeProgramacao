#include <bits/stdc++.h>
using namespace std;



void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<vector<bool>> dp(2*k+1, vector<bool>(n));
    // true se alice tem estrat. vencedora e false caso contrário
    for (int i=0; i<n; i++) dp[0][i] = (s[i] == 'A');

    for (int j=1; j<=2*k; j++) {
        if (j % 2) {
            // Bob
            // bob só ganha, se existir uma jogada que dá a estratégia vencedora pra ele em j-1
            for (int i=0; i<n; i++) {
                bool bob = false;
                for (int x=0; !bob && x < adj[i].size(); x++) {
                    bob = !dp[j-1][adj[i][x]];
                }
                dp[j][i] = !bob;
            }

        } else {
            // Alice
            // alice só ganha, se existir uma jogada que dá a estratégia vencedora pra ela em j-1
            for (int i=0; i<n; i++) {
                bool alice = false;
                for (int x=0; !alice && x < adj[i].size(); x++) {
                    alice = dp[j-1][adj[i][x]];
                }
                dp[j][i] = alice;
            }
        }
    }

    cout << (dp[2*k][0] ? "Alice" : "Bob") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}