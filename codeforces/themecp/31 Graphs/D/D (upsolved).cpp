#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int n;
    cin >> n;
    vector<array<int,3>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll dx = a[i][0] - a[j][0],
                dy = a[i][1] - a[j][1],
                dz = a[i][2] + a[j][2];
            if (dx*dx + dy*dy == dz*dz) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> color(n, -1);
    bool ok = 0;
    for (int i=0; !ok && i<n; i++) if (color[i] == -1) {
        color[i] = 0;
        stack<int> stk; stk.push(i);
        int size[2] = {0, 0};

        bool bip = 1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();
            size[color[curr]]++;

            for (int neighbor : adj[curr]) {
                if (color[neighbor] != -1) {
                    if (color[neighbor] == color[curr]) bip = 0;
                } else {
                    color[neighbor] = 1 - color[curr];
                    stk.push(neighbor);
                }
            }
        }

        ok = bip && (size[0] != size[1]);
    }

    cout << (ok ? "YES" : "NO") << '\n';
}
