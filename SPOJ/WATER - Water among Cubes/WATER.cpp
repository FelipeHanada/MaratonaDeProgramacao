#include <bits/stdc++.h>
using namespace std;


int grid[100][100];
int n, m;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int solve() {
    vector<vector<char>> seen(n, vector<char>(m, 0));
    // 0 not seen
    // 1 common seen
    // 2 not seen border
    // 3 border seen
    set<pair<int, pair<int, int>>> borderq;

    for (int i=1; i<n-1; i++) {
        borderq.insert({grid[i][0], {i, 0}});
        borderq.insert({grid[i][m-1], {i, m-1}});
        seen[i][0] = seen[i][m-1] = 2;
    }
    for (int j=1; j<m-1; j++) {
        borderq.insert({grid[0][j], {0, j}});
        borderq.insert({grid[n-1][j], {n-1, j}});
        seen[0][j] = seen[n-1][j] = 2;
    }
    seen[0][0] = seen[0][m-1] = seen[n-1][0] = seen[n-1][m-1] = 3;
    
    int ans = 0;
    while (!borderq.empty()) {
        // run bfs for every tile that has height < start height and marks it as seen
        // tiles that have height >= start height should be marked as a border as well
        // ans += start height - height

        auto start = borderq.begin();
        pair<int, int> startp = start->second;
        borderq.erase(borderq.begin());

        if (seen[startp.first][startp.second] % 2) continue;
        seen[startp.first][startp.second] = 3;

        queue<pair<int, int>> bfs;
        bfs.emplace(startp);

        while (!bfs.empty()) {
            pair<int, int> curr = bfs.front(); bfs.pop();
            if (seen[curr.first][curr.second] == 1) continue;
            seen[curr.first][curr.second] = true;
            ans += grid[startp.first][startp.second] - grid[curr.first][curr.second];

            for (int i=0; i<4; i++) {
                int x = curr.first + dx[i], y = curr.second + dy[i];

                if (x > 0 && x < n-1 && y > 0 && y < m-1 && seen[x][y] == 0) {
                    if (grid[x][y] < grid[startp.first][startp.second]) {
                        bfs.emplace((pair<int, int>){x, y});
                    } else {
                        borderq.insert({grid[x][y], {x, y}});
                        seen[x][y] = 2;
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    string trash;
    for (int test=0; test<t; test++) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << solve() << "\n";

        if (test < t-1)
            getline(cin, trash);
    }
}
