#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1000;
int n;
int ans[1000][1000];

#define pii pair<int, int>
#define f first
#define s second

pii moves[8] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n, -1));
    
    // run a BFS starting in [0][0] 
    ans[0][0] = 0;
    queue<pair<pii, int>> bfs;
    bfs.push({{0, 0}, 0});
    while (!bfs.empty()) {
        auto [x, d] = bfs.front();
        bfs.pop();

        for (int i=0; i<8; i++) {
            pii y = {x.f + moves[i].f, x.s + moves[i].s};
            if (y.f >= 0 && y.f < n && y.s >= 0 && y.s < n && ans[y.f][y.s] == -1) {
                ans[y.f][y.s] = d + 1;
                bfs.push({y, d+1});
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}