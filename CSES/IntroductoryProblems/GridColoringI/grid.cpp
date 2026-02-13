#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 500;
int n, m;
char grid[MAX][MAX];
char curr[MAX][MAX];


bool solve(int x) {
    int i=x/m, j=x%m;
    for (char c='A'; c<='D'; c++) {
        if (grid[i][j] == c) continue;
        if (i>0 && curr[i-1][j] == c) continue;
        if (j>0 && curr[i][j-1] == c) continue;
        curr[i][j] = c;
        if ((i == n-1 && j==m-1) || solve(x+1)) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    bool ok = solve(0);
    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << curr[i][j];
            }
            cout << '\n';
        }
    }
}