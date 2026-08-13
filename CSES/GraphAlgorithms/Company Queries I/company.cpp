#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> p(n);
    p[0] = -1;
    for (int i=1; i<n; i++) {
        cin >> p[i]; p[i]--;
    }

    vector<vector<int>> up(31, vector<int>(n));
    up[0] = p;
    for (int i=1; i<31; i++) {
        for (int j=0; j<n; j++) {
            if (up[i-1][j] == -1) up[i][j] = -1;
            else up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    while (q--) {
        int x, k; cin >> x >> k; x--;

        for (int i=30; x >= 0 && i>=0; i--) {
            while (x >= 0 && k >= (1 << i)) {
                x = up[i][x];
                k -= (1 << i);
            }
        }
        
        if (x == -1) cout << -1 << '\n';
        else cout << x + 1 << '\n';
    }
}
