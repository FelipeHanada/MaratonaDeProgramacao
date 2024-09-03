#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_M = 500, MAX_N = 500;
int m, n;
int elevations[MAX_M][MAX_N];

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    cin >> m >> n;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> elevations[i][j];
        }
    }
}
