#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second
constexpr int MAX_N = 500;
constexpr int MAX_M = 500;
int n, m;
int grid[MAX_N][MAX_M];
bool seen[MAX_N][MAX_M];

pii moves[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        fill_n(seen[i], m, false);
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    set<pii> waypoints;
    int x;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> x;
            if (x) {
                waypoints.insert(make_pair(i, j));
            }
        }
    }

    priority_queue<pair<int, pii>> pq;
    pq.emplace(make_pair(0, *waypoints.begin()));
    waypoints.erase(waypoints.begin());

    int best = 0;
    while (!waypoints.empty()) {
        pair<int, pii> curr = pq.top(); pq.pop();
        if (seen[curr.s.f][curr.s.s]) continue;
        seen[curr.s.f][curr.s.s] = true;

        auto it = waypoints.find(curr.s);
        if (it != waypoints.end()) {
            waypoints.erase(it);
            best = max(best, -curr.f);
        }

        for (int i=0; i<4; i++) {
            int x = curr.s.f + moves[i].f, y = curr.s.s + moves[i].s;
            
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            pq.emplace(make_pair(
                min(curr.f, -abs(grid[curr.s.f][curr.s.s] - grid[x][y])),
                make_pair(x, y)
            ));
        }
    }

    cout << best << '\n';
}