#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<array<int,4>> rect(n*n+1, {0, 0, 0, 0});

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
            rect[grid[i][j]][0] = min(rect[grid[i][j]][0], i);
            rect[grid[i][j]][1] = min(rect[grid[i][j]][1], j);
            rect[grid[i][j]][2] = max(rect[grid[i][j]][2], i);
            rect[grid[i][j]][3] = max(rect[grid[i][j]][3], j);
        }
    }

    int b = ceil(sqrt(n));
    vector<vector<int>> sqrtmin(b, vector<int>(b, INT32_MAX));
    vector<vector<int>> sqrtmax(b, vector<int>(b, INT32_MIN));
    for (int i=0; i<n; i+=b) {
        for (int j=0; j<n; j+=b) {
            for (int bi=0; bi<b && i+bi < n; bi++) {
                for (int bj=0; bj<b && j+bj < n; bj++) {
                    sqrtmin[i/b][j/b] = min(sqrtmin[i/b][j/b], grid[i+bi][j+bj]);
                    sqrtmax[i/b][j/b] = max(sqrtmax[i/b][j/b], grid[i+bi][j+bj]);
                }
            }
        }
    }

    auto query_min = [&](int x1, int y1, int x2, int y2) -> int {
        int ans = INT32_MAX;
        while (x1 % b) {
            for (int j=y1; j<=y2; j++) {
                ans = min(ans, grid[x1][j]);
            }
            x1++;
        }
        while ((x2 - 1) % b) {
            for (int j=y1; j<=y2; j++) {
                ans = min(ans, grid[x2][j]);
            }
            x2--;
        } x2++;
        while (y1 % b) {
            for (int i=x1; i<=x2; i++) {
                ans = min(ans, grid[i][y1]);
            }
            y1++;
        }
        while ((y2 - 1) % b) {
            for (int i=x1; i<=x2; i++) {
                ans = min(ans, grid[i][y2]);
            }
            y2--;
        } y2++;
        while (x1 < x2) {
            for (int j=y1; j<y2; j+=b) {
                ans = min(ans, sqrtmin[x1/b][j/b]);
            }
            x1 += b;
        }
        return ans;
    };
    auto query_max = [&](int x1, int y1, int x2, int y2) -> int {
        int ans = INT32_MIN;
        while (x1 % b) {
            for (int j=y1; j<=y2; j++) {
                ans = max(ans, grid[x1][j]);
            }
            x1++;
        }
        while ((x2 - 1) % b) {
            for (int j=y1; j<=y2; j++) {
                ans = max(ans, grid[x2][j]);
            }
            x2--;
        } x2++;
        while (y1 % b) {
            for (int i=x1; i<=x2; i++) {
                ans = max(ans, grid[i][y1]);
            }
            y1++;
        }
        while ((y2 - 1) % b) {
            for (int i=x1; i<=x2; i++) {
                ans = max(ans, grid[i][y2]);
            }
            y2--;
        } y2++;
        while (x1 < x2) {
            for (int j=y1; j<y2; j+=b) {
                ans = max(ans, sqrtmax[x1/b][j/b]);
            }
            x1 += b;
        }
        return ans;
    };

    int ans = 0;
    for (int i=1; i<=n*n; i++) {
        int small = query_min(rect[i][0], rect[i][1], rect[i][2], rect[i][3]);
        int big = query_max(rect[i][0], rect[i][1], rect[i][2], rect[i][3]);
        if (small = big) ans++;
    }

    cout << ans << '\n';
}
