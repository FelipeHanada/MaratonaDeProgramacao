#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = true;
    }

    int best = INT32_MAX;
    for (int mask=0; mask<(1<<(n+1)); mask++) {
        int count = 0;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (((mask&(1<<i)) && !(mask&(1<<j))) || (!(mask&(1<<i)) && (mask&(1<<j)))) continue;
                if (adj[i][j]) count++;
            }
        }

        best = min(best, count);
    }

    cout << best << '\n';
}
