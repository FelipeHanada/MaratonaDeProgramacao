#include <bits/stdc++.h>
using namespace std;


#define _1 first
#define _2 second

void solve() {
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    vector<int> deg(n, 0);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    int ans = INT32_MIN;

    multiset<int> ms;
    for (int i=0; i<n; i++) ms.insert(deg[i]);
    for (int i=0; i<n; i++) {
        ms.extract(deg[i]);
        for (int neighbor : adj[i]) {
            ms.extract(deg[neighbor]);
            ms.insert(deg[neighbor] - 1);
        }

        ans = max(ans, deg[i] + *ms.rbegin() - 1);

        for (int neighbor : adj[i]) {
            ms.extract(deg[neighbor] - 1);
            ms.insert(deg[neighbor]);
        }
        ms.insert(deg[i]);
    }
    
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}