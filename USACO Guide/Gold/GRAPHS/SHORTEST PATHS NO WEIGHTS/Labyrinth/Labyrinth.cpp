#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second


pii moves[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
constexpr int MAX_NM = 1000;
int n, m;
pii a, b;
char grid[MAX_NM][MAX_NM];
int dist[MAX_NM][MAX_NM];


int main() {
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        fill_n(dist[i], m, -1);
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') a = make_pair(i, j);
            if (grid[i][j] == 'B') b = make_pair(i, j);
            if (grid[i][j] == '#') dist[i][j] = INT32_MAX; // just a flag
        }
    }

    queue<pii> bfs;
    bfs.push(a);
    dist[a.f][a.s] = 0;
    while (!bfs.empty()) {
        pii curr = bfs.front(); bfs.pop();
        for (int i=0; i<4; i++) {
            int y = curr.f + moves[i].f, x = curr.s + moves[i].s;
            if (y < 0 || y >= n || x < 0 || x >= m || dist[y][x] >= 0) continue;
            dist[y][x] = dist[curr.f][curr.s] + 1;
            bfs.push(make_pair(y, x));
        }
    }

    if (dist[b.f][b.s] < 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << dist[b.f][b.s] << '\n';

    stack<char> path;
    pii curr = b;
    int d = dist[b.f][b.s];
    while (d) {
        if (curr.f > 0 && dist[curr.f - 1][curr.s] == d - 1) {
            path.push('D');
            curr.f--;
        } else if (curr.f < n-1 && dist[curr.f + 1][curr.s] == d - 1) {
            path.push('U');
            curr.f++;
        } else if (curr.s > 0 && dist[curr.f][curr.s - 1] == d - 1) {
            path.push('R');
            curr.s--;
        } else {
            path.push('L');
            curr.s++;
        }
        d--;
    }

    while (!path.empty()) {
        cout << path.top();
        path.pop();
    }
    cout << '\n';
}
