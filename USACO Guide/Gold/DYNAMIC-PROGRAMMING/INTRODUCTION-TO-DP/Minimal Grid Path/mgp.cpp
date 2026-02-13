#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 3000;
int n;
char grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 0;
    for (int i=1; i<n; i++) {
        vector<tuple<int, char, pair<int, int>>> d;
        int x = 0, y = i;
        while (y >= 0) {
            d.push_back(make_tuple(
                min(
                    (x>0) ? dp[x-1][y] : INT32_MAX,
                    (y>0) ? dp[x][y-1] : INT32_MAX
                ),
                grid[x][y],
                make_pair(x, y)
            ));

            x++; y--;
        }
        sort(d.begin(), d.end());

        for (int j=0; j<d.size(); j++) {
            if (j > 0 && get<0>(d[j]) == get<0>(d[j-1]) && get<1>(d[j]) == get<1>(d[j-1])) {
                dp[get<2>(d[j]).first][get<2>(d[j]).second] = dp[get<2>(d[j-1]).first][get<2>(d[j-1]).second];
            } else {
                dp[get<2>(d[j]).first][get<2>(d[j]).second] = j;
            }
        }
    }

    for (int i=1; i<n; i++) {
        vector<tuple<int, char, pair<int, int>>> d;
        int x = i, y = n-1;
        while (x < n) {
            d.push_back(make_tuple(
                min(dp[x-1][y], dp[x][y-1]),
                grid[x][y],
                make_pair(x, y)
            ));

            x++; y--;
        }
        sort(d.begin(), d.end());

        for (int j=0; j<d.size(); j++) {
            if (j > 0 && get<0>(d[j]) == get<0>(d[j-1]) && get<1>(d[j]) == get<1>(d[j-1])) {
                dp[get<2>(d[j]).first][get<2>(d[j]).second] = dp[get<2>(d[j-1]).first][get<2>(d[j-1]).second];
            } else {
                dp[get<2>(d[j]).first][get<2>(d[j]).second] = j;
            }
        }
    }

    stack<char> sol;
    int i=n-1, j=n-1;
    while (i > 0 && j > 0) {
        sol.push(grid[i][j]);
        
        if (dp[i-1][j] < dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    while (i > 0) {
        sol.push(grid[i][0]);
        i--;
    }
    while (j > 0) {
        sol.push(grid[0][j]);
        j--;
    }

    cout << grid[0][0];
    while (!sol.empty()) {
        cout << sol.top();
        sol.pop();
    }
    cout << '\n';
}
