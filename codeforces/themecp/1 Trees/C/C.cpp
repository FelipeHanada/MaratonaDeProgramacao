#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nleafs = 0;
    vector<int> leafs(n, 0);
    for (int i=0; i<n; i++) {
        if (adj[i].size() == 1) {
            nleafs++;
            leafs[adj[i][0]]++;
        }
    }

    int ans = INT32_MAX;
    for (int i=0; i<n; i++) {
        ans = min(ans, nleafs - leafs[i] - (int)(adj[i].size() == 1));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
