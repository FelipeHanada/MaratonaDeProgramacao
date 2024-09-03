#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int field[n][n] = {};
    int prefix_array[n][n+1] = {};
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            field[i][j] = x;

            for (int ki=-k; ki<=k && i+ki<n; ki++) {
                if (i + ki < 0) continue;

                int l = k - abs(ki);

                prefix_array[i+ki][max(0, j-l)] += x;
                prefix_array[i+ki][min(n, j+l+1)] -= x;
            }

        }
    }

    int maximum = INT32_MIN;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            prefix_array[i][j+1] += prefix_array[i][j];
            maximum = max(maximum, prefix_array[i][j]);
        }
    }

    cout << maximum << endl;
}