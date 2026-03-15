#include <bits/stdc++.h>
using namespace std;


constexpr int SIZE = 200;
int grid[SIZE+1][SIZE+1];
int cnt[SIZE+1][SIZE+1];

int p1[SIZE+1][SIZE+1];
int p2[SIZE+1][SIZE+1];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i=0; i<=SIZE; i++) fill_n(grid[i], SIZE+1, 0);
    for (int i=0; i<=SIZE; i++) fill_n(cnt[i], SIZE+1, 0);

    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        grid[x1][y1]++;
        grid[x1][y2+1]--;
        grid[x2+1][y1]--;
        grid[x2+1][y2+1]++;
    }

    int curr = 0;
    for (int i=1; i<=SIZE; i++) {
        for (int j=1; j<=SIZE; j++) {
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];

            if (grid[i][j] == k - 1) cnt[i][j] = 1;
            if (grid[i][j] == k) {
                curr++;
                cnt[i][j] = -1;
            }
        }
    }

    for (int i=0; i<=SIZE; i++) {
        for (int j=0; j<=SIZE; j++) {
            p1[i][j] = cnt[i][j];
            if (j) p1[i][j] += p1[i][j-1];

            p2[j][i] = cnt[i][j];
            if (i) p2[j][i] += p2[j][i-1]; 
        }
    }

    int ans = 0;
    for (int k=0; k<SIZE; k++) {

        for (int i=0; i<k; i++) {
            for (int j=i+1; j<=SIZE; j++) {
                int best = 0, curr = 0;
                
            }
        }

    }

    cout << curr + ans << '\n';
}