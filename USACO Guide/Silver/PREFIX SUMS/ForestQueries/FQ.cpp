#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1000;
int prefix[MAX_N+1][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    prefix[0][0] = 0;
    for (int i=1; i<n; i++) {
        prefix[i][0] = prefix[0][i] = 0;
    }

    char c;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c;

            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] +
                ((c == '*') ? 1 : 0);
        }
    }

    int x1, y1, x2, y2;
    for (int i=0; i<q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1] << '\n';
    }
}