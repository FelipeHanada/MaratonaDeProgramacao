#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        grid[a][b] = -1;
    }

    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == -1) continue;
            grid[i][j] = sum;
            sum++;
        }
    }

    while (t--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (grid[a][b] == -1) {
            cout << "Waste\n";
        } else {
            if (grid[a][b]%3 == 0) {
                cout << "Carrots\n";
            } else if (grid[a][b]%3 == 1) {
                cout << "Kiwis\n";
            } else {
                cout << "Grapes\n";
            }
        }
    }
}
