#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int MAX_N = 500;
char grid[MAX_N][MAX_N];

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> grid[i][j];
            }
        }

        bool ok = 1;

        for (int i=0; ok && i<n; i++) {
            bool flip = 0;
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'U') {
                    if (flip) {
                        grid[i][j] = 'W';
                        grid[i+1][j] = 'B';
                    } else {
                        grid[i][j] = 'B';
                        grid[i+1][j] = 'W';
                    }
                    flip = !flip;
                }
            }

            if (flip) ok = 0;
        }

        if (!ok) {
            cout << "-1" << '\n';
            continue;
        }

        for (int j=0; j<m; j++) {
            bool flip = 0;
            for (int i=0; i<n; i++) {
                if (grid[i][j] == 'L') {
                    if (flip) {
                        grid[i][j] = 'W';
                        grid[i][j+1] = 'B';
                    } else {
                        grid[i][j] = 'B';
                        grid[i][j+1] = 'W';
                    }
                    flip = !flip;
                }
            }
            
            if (flip) ok = 0;
        }

        if (!ok) {
            cout << "-1" << '\n';
            continue;
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
}
