#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }

    bool dp[k*2+1][n];
    for (int i=0; i<n; i++) dp[0][i] = (s[i] == 'A');

    for (int i=1; i<=k*2; i++) {
        for (int j=0; j<n; j++) {
            bool alice;
            if (!(i%2)) { // alice plays
                alice = false;
                for (int x=0; !alice && x<adj[j].size(); x++) {
                    if (dp[i-1][adj[j][x]]) alice = true;
                }
            } else { // bob plays
                alice = true;
                for (int x=0; alice && x<adj[j].size(); x++) {
                    if (!dp[i-1][adj[j][x]]) alice = false;
                }
            }
            dp[i][j] = alice;
        }
    }

    cout << ((dp[2*k][0]) ? "Alice" : "Bob") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}