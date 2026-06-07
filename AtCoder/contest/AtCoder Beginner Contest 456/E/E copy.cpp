#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);


void solve() { _
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

    int w;
    cin >> w;
    vector<string> h(n);
    for (int i=0; i<n; i++) cin >> h[i];
    
    set<int> a;
    for (int i=0; i<n; i++) if (h[i][0] == 'o') a.insert(i);
    for (int i=0; i<w-1; i++) {
        set<int> next;
        for (auto x : a) {
            if (h[x][i+1] == 'o') next.insert(x);
            for (int neighbor : adj[x]) {
                if (h[neighbor][i+1] == 'o') next.insert(neighbor);
            }
        }
        swap(a, next);
    }

    set<int> b;
    for (int i=0; i<n; i++) if (h[i][w-1] == 'o') b.insert(i);
    for (int i=w-1; i>1; i--) {
        set<int> next;
        for (auto x : b) {
            if (h[x][i-1] == 'o') next.insert(x);
            for (int neighbor : adj[x]) {
                if (h[neighbor][i-1] == 'o') next.insert(neighbor);
            }
        }
        swap(b, next);
    }

    bool ok = 0;
    for (int x : a) {
        if (b.count(x)) ok = 1;
        for (int neighbor : adj[x]) {
            if (b.count(neighbor)) ok = 1;
        }
    }

    cout << (ok ? "Yes" : "No") << '\n';
}

/*
dp[i][j] = 1
    if its possible to end at vertex i on the j-th day spending all noons on holydays


*/

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}
