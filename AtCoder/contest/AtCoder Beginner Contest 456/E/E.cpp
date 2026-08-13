#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);


void solve() { _
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    int w;
    cin >> w;
    vector<string> h(n);
    for (int i=0; i<n; i++) cin >> h[i];
    
    set<pair<int, int>> curr;
    for (int i=0; i<n; i++) if (h[i][0] == 'o') curr.insert({i, i});

    for (int i=0; i<w-1; i++) {
        set<pair<int, int>> next;
        for (auto [ start, x ] : curr) {
            if (h[x][i+1] == 'o') next.insert({ start, x });
            for (int neighbor : adj[x]) {
                if (h[neighbor][i+1] == 'o')
                    next.insert({ start, neighbor });
            }
        }

        swap(curr, next);
    }

    bool ok = 0;
    for (auto [ start, x ] : curr) {
        if (start == x || adj[x].count(start)) {
            ok = 1;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}
