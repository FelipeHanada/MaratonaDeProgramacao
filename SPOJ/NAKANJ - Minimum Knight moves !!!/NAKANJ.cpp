#include <bits/stdc++.h>
using namespace std;


int dx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans[8][8][8][8];
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            for (int k=0; k<8; k++) {
                fill_n(ans[i][j][k], 8, INT32_MAX);
            }
        }
    }

    for (int x1=0; x1<8; x1++) {
        for (int y1=0; y1<8; y1++) {
            queue<pair<int, int>> q;
            q.emplace((pair<int, int>){ x1, y1 });
            ans[x1][y1][x1][y1] = 0;
            while (!q.empty()) {
                pair<int, int> curr = q.front(); q.pop();
        
                for (int i=0; i<8; i++) {
                    int x = curr.first + dx[i], y = curr.second + dy[i];
                    if (x < 0 || x >= 8 || y < 0 || y >= 8) continue;
                    if (ans[x1][y1][x][y] < INT32_MAX) continue;
                    
                    ans[x1][y1][x][y] = ans[x1][y1][curr.first][curr.second] + 1;
                    q.emplace((pair<int, int>){ x, y });
                }
            }
        }
    }

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << ans[s1[0]-'a'][s1[1]-'1'][s2[0]-'a'][s2[1]-'1'] << "\n";
    }
}
