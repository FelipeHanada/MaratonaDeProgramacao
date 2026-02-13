#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int ans = 0;    
    int z;
    for (int i=0; i<n; i++) {
        cin >> z;
        if (z <= y) ans++;
    }
    for (int i=0; i<m; i++) {
        cin >> z;
        if (z <= x) ans++;
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
