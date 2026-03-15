#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<array<int,4>> rect(n*n+1, {INT32_MAX, INT32_MAX, INT32_MIN, INT32_MIN});
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];

            rect[grid[i][j]][0] = min(rect[grid[i][j]][0], i);
            rect[grid[i][j]][1] = min(rect[grid[i][j]][1], j);
            rect[grid[i][j]][2] = max(rect[grid[i][j]][2], i);
            rect[grid[i][j]][3] = max(rect[grid[i][j]][3], j);
        }
    }

    // each color defines a rect
    // a color cant be the first painted
    //      iff. there is a point of this color inside another rect
    //      that is, if the point is contained by both intervals at the same time

    vector<vector<int>> diff(n+1, vector<int>(n+1, 0));
    int painted = 0;
    for (int i=1; i<=n*n; i++) {
        if (rect[i][0] == INT32_MAX) continue;

        painted++;

        diff[rect[i][0]][rect[i][1]]++;
        diff[rect[i][0]][rect[i][3]+1]--;
        diff[rect[i][2]+1][rect[i][1]]--;
        diff[rect[i][2]+1][rect[i][3]+1]++;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i) diff[i][j] += diff[i-1][j];
            if (j) diff[i][j] += diff[i][j-1];
            if (i && j) diff[i][j] -= diff[i-1][j-1];
        }
    }

    set<int> ans;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (diff[i][j] > 1) {
                ans.insert(grid[i][j]);
            }
        }
    }


    if (painted == 1) {
        cout << n*n-1 << '\n';
    } else {
        cout << n*n - ans.size() << '\n';
    }
}
