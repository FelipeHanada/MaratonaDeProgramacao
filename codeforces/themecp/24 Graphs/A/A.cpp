#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, m;
    cin >> n >> m;
    bool unknown = 0;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (x == y) unknown = 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (unknown) {
        cout << "unknown topology\n";
        return 0;
    }

    bool path = 1;
    int deg2 = 0;
    for (int i=0; i<n; i++) {
        deg2 += (adj[i].size() == 2);
        if (adj[i].size() == 0 || adj[i].size() > 2) path = 0;
    }

    if (path) {
        if (deg2 == n - 2) {
            cout << "bus topology\n";
            return 0;
        }
        
        if (deg2 == n) {
            cout << "ring topology\n";
            return 0;
        }
    }

    int center = -1;
    for (int i=0; i<n; i++) {
        if (adj[i].size() > 1) {
            if (center == -1) center = i;
            else if (center != i) unknown = 1;
        } else if (adj[i].size() == 1) {
            if (center == -1) {
                center = adj[i][0];
            } else if (center != adj[i][0]) {
                unknown = 1;
            }
        } else {
            unknown = 1;
        }
    }

    if (unknown == 0) {
        cout << "star topology\n";
    } else {
        cout << "unknown topology\n";
    }
}
