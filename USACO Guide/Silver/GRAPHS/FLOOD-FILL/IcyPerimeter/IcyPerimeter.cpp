#include <bits/stdc++.h>
using namespace std;


const int MAX_N = 1000;
int n;
char cells[MAX_N][MAX_N];
int seen[MAX_N][MAX_N];

pair<int, int> flood_fill(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) return { 0, 1 };
    if (cells[i][j] == '.') return {0, 1};
    if (seen[i][j]) return {0, 0};

    seen[i][j] = true;

    auto top = flood_fill(i-1, j);
    auto bottom = flood_fill(i+1, j);
    auto left = flood_fill(i, j-1);
    auto right = flood_fill(i, j+1);

    return {
        1 + top.first + bottom.first + left.first + right.first,
        top.second + bottom.second + left.second + right.second
    };
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> cells[i][j];
            seen[i][j] = false;
        }
    }

    pair<int, int> ans = {INT32_MIN, 0};
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!seen[i][j] && cells[i][j] == '#') {
                pair<int, int> ff = flood_fill(i, j);
                if (ff.first > ans.first || (ff.first == ans.first && ff.second < ans.second)) {
                    ans = ff;
                }
            }
        }
    }

    cout << ans.first << " " << ans.second << endl;
}
