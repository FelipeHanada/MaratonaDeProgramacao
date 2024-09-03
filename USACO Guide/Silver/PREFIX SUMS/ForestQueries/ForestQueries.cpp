#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> prefix(n + 1);
    for (int i=0; i<=n; i++) prefix[0].push_back(0);

    for (int i=1; i<=n; i++) {
        prefix[i].push_back(0);
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;

            prefix[i].push_back(prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1]);
            prefix[i][j] += (c == '*') ? 1 : 0;
        }
    }

    int y1, x1, y2, x2;
    for (int i=0; i<q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1] << endl;
    }
}
