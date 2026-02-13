#include <bits/stdc++.h>
using namespace std;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char s[48];
bool seen[9][9];


int sol(int x, int y, int k) {
    if (k == 48) return 1;
    if (x == 1 && y == 7) return 0;

    int left = seen[x-1][y],
        right = seen[x+1][y],
        up = seen[x][y-1],
        down = seen[x][y+1];
    if (left && right && !up && !down) return 0;
    if (up && down && !left && !right) return 0;
    if (up + down + left + right == 4) return 0;

    seen[x][y] = true;
    int ans = 0;
    if (s[k] == '?') {
        for (int i=0; i<4; i++) {
            int currx = x + dx[i], curry = y + dy[i];
            if (seen[currx][curry]) continue;
            ans += sol(currx, curry, k+1);
        }
    } else {
        if (s[k] == 'L' && !seen[x-1][y]) ans = sol(x-1, y, k+1);
        else if (s[k] == 'R' && !seen[x+1][y]) ans = sol(x+1, y, k+1);
        else if (s[k] == 'U' && !seen[x][y-1]) ans = sol(x, y-1, k+1);
        else if (s[k] == 'D' && !seen[x][y+1]) ans = sol(x, y+1, k+1);
    }
    seen[x][y] = false;
    return ans;
}

int main() {
    for (int i=0; i<48; i++) cin >> s[i];

    fill_n(seen[0], 9, true);
    for (int i=1; i<8; i++) {
        fill_n(seen[i], 9, false);
        seen[i][0] = seen[i][8] = true;
    }
    fill_n(seen[8], 9, true);

    cout << sol(1, 1, 0) << '\n';
}
