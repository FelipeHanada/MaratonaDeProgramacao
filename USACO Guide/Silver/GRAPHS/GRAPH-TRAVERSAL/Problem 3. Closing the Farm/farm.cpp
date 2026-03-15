#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }
    reverse(a.begin(), a.end());

    vector<int> comp(n);
    iota(comp.begin(), comp.end(), 0);

    vector<bool> ans(n);
    set<int> vertices;
    int comps = 0;
    for (int i=0; i<n; i++) {
        vertices.insert(a[i]); comps++;

        set<int> s;
        for (int neighbor : adj[a[i]]) {
            if (!vertices.count(neighbor)) continue;

            s.insert(comp[neighbor]);
        }

        comps -= s.size();
        for (int j=0; j<n; j++) if (s.count(comp[j])) {
            comp[j] = a[i];
        }

        ans[i] = comps < 2;
    }
    reverse(ans.begin(), ans.end());

    for (bool x : ans) {
        cout << (x ? "YES" : "NO") << '\n';
    }
}