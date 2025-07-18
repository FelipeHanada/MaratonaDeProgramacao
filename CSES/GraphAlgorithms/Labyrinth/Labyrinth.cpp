#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> p;
constexpr char S = 'A';
constexpr char E = 'B';
constexpr char W = '#';
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char grid[1000][1000];
int dist[1000][1000];
p path[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        fill_n(dist[i], m, 0);
        fill_n(path[i], m, (p){-1, -1});
    }

    p s, e;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == S) s = {i, j};
            else if (grid[i][j] == E) e = {i, j};
            else if (grid[i][j] == W) path[i][j] = {0, 0};
        }
    }

    queue<p> bfs;
    bfs.push(s);
    dist[s.first][s.second] = 0;
    path[s.first][s.second] = s;

    while (!bfs.empty() && path[e.first][e.second].first == -1) {
        p curr = bfs.front(); bfs.pop();

        for (int i=0; i<4; i++) {
            p d = {curr.first + dx[i], curr.second + dy[i]};

            if (path[d.first][d.second].first != -1
                || d.first < 0 || d.first >= n
                || d.second < 0 || d.second >= m)
                continue;

            dist[d.first][d.second] = dist[curr.first][curr.second] + 1;
            path[d.first][d.second] = curr;
            bfs.push(d);
        }
    }

    if (path[e.first][e.second].first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[e.first][e.second] << "\n";

        stack<p> stc;
        p curr = e;
        stc.push(curr);
        while ((curr = path[curr.first][curr.second]) != s) {
            stc.push(curr);
        }
        stc.push(s);

        while (stc.size() > 1) {
            curr = stc.top(); stc.pop();
            p next = stc.top();
            if (next.first > curr.first) cout << "D";
            else if (next.first < curr.first) cout << "U";
            else if (next.second > curr.second) cout << "R";
            else cout << "L";
        }
        cout << "\n";
    }
}
