#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            int max_neighbor = INT32_MIN;
            if (i > 0) max_neighbor = max(max_neighbor, a[i-1][j]);
            if (i < n-1) max_neighbor = max(max_neighbor, a[i+1][j]);
            if (j > 0) max_neighbor = max(max_neighbor, a[i][j-1]);
            if (j < m-1) max_neighbor = max(max_neighbor, a[i][j+1]);
            a[i][j] = min(a[i][j], max_neighbor);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}