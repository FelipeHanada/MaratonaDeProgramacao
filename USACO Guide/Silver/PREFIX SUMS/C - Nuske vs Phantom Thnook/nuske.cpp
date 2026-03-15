#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char x;
            cin >> x;
            grid[i][j] = (x == '1');
        }
    }

    vector<vector<int>> vertices(n+1, vector<int>(m+1, 0));
    vector<vector<int>> edges1(n+1, vector<int>(m+1, 0));
    vector<vector<int>> edges2(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            vertices[i][j] = vertices[i-1][j] + vertices[i][j-1] - vertices[i-1][j-1];
            edges1[i][j] = edges1[i-1][j] + edges1[i][j-1] - edges1[i-1][j-1];
            edges2[i][j] = edges2[i-1][j] + edges2[i][j-1] - edges2[i-1][j-1];

            if (grid[i-1][j-1]) {
                vertices[i][j]++;
                if (i-2 >= 0) edges1[i][j] += grid[i-2][j-1];
                if (j-2 >= 0) edges2[i][j] += grid[i-1][j-2];
            }
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int vcnt = vertices[x2][y2] - vertices[x1-1][y2] - vertices[x2][y1-1] + vertices[x1-1][y1-1];
        int ecnt = edges1[x2][y2] - edges1[x1][y2] - edges1[x2][y1-1] + edges1[x1][y1-1]
                    + edges2[x2][y2] - edges2[x1-1][y2] - edges2[x2][y1] + edges2[x1-1][y1];

        cout << vcnt - ecnt << '\n';
    }
}
