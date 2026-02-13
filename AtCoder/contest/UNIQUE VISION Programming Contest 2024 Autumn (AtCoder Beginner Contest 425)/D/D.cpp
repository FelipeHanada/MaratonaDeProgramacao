#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second


pii moves[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int h, w;
bool check(const vector<vector<bool>>& grid, int i, int j) {
    if (i < 0 || i >= h || j < 0 || j >= w) return false;
    int count = 0;
    if (i-1 >= 0 && grid[i-1][j]) count++;
    if (i+1 < h && grid[i+1][j]) count++;
    if (j-1 >= 0 && grid[i][j-1]) count++;
    if (j+1 < w && grid[i][j+1]) count++;
    return count == 1;
}

int main() {
    cin >> h >> w;
    vector<vector<bool>> grid(h, vector<bool>(w, false));

    set<pii> born_today;
    int ans = 0;
    char c;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> c;
            if (c == '#') {
                grid[i][j] = true;
                born_today.insert(make_pair(i, j));
                ans++;
            }
        }
    }

    set<pii> born_tomorrow;
    while (!born_today.empty()) {
        born_tomorrow.clear();
        for (auto [x, y] : born_today) {
            for (int i=0; i<4; i++) {
                if (check(grid, x+moves[i].f, y+moves[i].s) && !grid[x+moves[i].f][y+moves[i].s]) {
                    born_tomorrow.insert({x+moves[i].f, y+moves[i].s});
                }
            }
        }

        ans += born_tomorrow.size();

        for (auto [x, y] : born_tomorrow) {
            grid[x][y] = true;
        }

        swap(born_today, born_tomorrow);
    }

    cout << ans << '\n';
}