#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> next(n);
    for (int i=0; i<n; i++) cin >> next[i];
    for (int i=0; i<n; i++) next[i]--;

    vector<vector<int>> jump(30, vector<int>(n));
    jump[0] = next;
    for (int i=1; i<jump.size(); i++) {
        for (int j=0; j<n; j++) {
            jump[i][j] = jump[i-1][jump[i-1][j]];
        }
    }

    while (q--) {
        int x, k; cin >> x >> k; x--;

        for (int i=jump.size()-1; k; i--) {
            while ((1 << i) <= k) {
                x = jump[i][x];
                k -= (1 << i);
            }
        }

        cout << x + 1 << '\n';
    }
}