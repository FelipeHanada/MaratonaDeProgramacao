#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int j=0; j<l; j++) {
            cin >> a[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << a[x][y] << '\n';
}
