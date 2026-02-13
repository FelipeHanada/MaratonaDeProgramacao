#include <bits/stdc++.h>
using namespace std;

#define _1 first
#define _2 second
#define pii pair<int, int>
#define ll long long 


void precompute() {

}


constexpr int MAX_N = 2e5;
int grid[MAX_N+2][MAX_N+2];

pair<int, int> moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> pq(n*m);
    // for (int i=0; i<n+2; i++) grid[i][0] = grid[i][m+1] = INT32_MAX;
    // for (int j=0; j<m+2; j++) grid[0][j] = grid[n+1][j] = INT32_MAX;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> grid[i][j];
            pq[(i-1)*n+j-1] = {-grid[i][j], {i, j}};
        }
    }
    sort(pq.begin(), pq.end());

    set<pair<int, int>> sinks;
    {
        vector<vector<bool>> seen(n+2, vector(m+2, false));

        for (int i=0; i<n+2; i++) seen[i][0] = seen[i][m+1] = true;
        for (int j=0; j<m+2; j++) seen[0][j] = seen[n+1][j] = true;

        while (!pq.empty()) {
            // computes weakly connected components
            auto [h, pos] = pq.back(); pq.pop_back();
            if (seen[pos._1][pos._2]) continue;
            sinks.insert(pos);

            queue<pair<int, pair<int, int>>> bfs;
            bfs.push({-h, pos});
            seen[pos._1][pos._2] = true;
            while (!bfs.empty()) {
                auto curr = bfs.front(); bfs.pop();

                for (int i=0; i<4; i++) {
                    auto [di, dj] = moves[i];
                    int ni = curr._2._1+di, nj = curr._2._2+dj;
                    if (seen[ni][nj] || grid[ni][nj] < curr._1) continue;
                    seen[ni][nj] = true;
                    bfs.push({grid[ni][nj], {ni, nj}});
                }
            }
        }
    }

    cout << sinks.size() << '\n';

    int q;
    cin >> q;
    while (q--) {
        int r, c, x;
        cin >> r >> c >> x;

        grid[r][c] -= x;

        // run bfs on r, c, let the number of sinks found in this be k
        // wecan make (r,c) be a new sink and the new value is ANS - k + 1

        set<pair<int, int>> seen;
        queue<pair<int, pair<int, int>>> bfs;
        bfs.push({grid[r][c], {r, c}});
        seen.insert({r, c});

        int sinks_found = 0;

        while (!bfs.empty()) {
            auto curr = bfs.front(); bfs.pop();

            for (int i=0; i<4; i++) {
                auto [di, dj] = moves[i];
                int ni = curr._2._1+di, nj = curr._2._2+dj;

                if (ni == 0 || ni == n+1 || nj == 0 || nj == m+1 || seen.count({ni, nj}) || grid[ni][nj] < curr._1) continue;
                seen.insert({ni, nj});

                if (sinks.count({ni, nj})) {
                    sinks_found++;
                    sinks.erase({ni, nj});
                }

                bfs.push({grid[ni][nj], {ni, nj}});
            }
        }

        if (sinks_found) {
            sinks.insert({r, c});
        }

        cout << sinks.size() << '\n';
    }
}

int main() {
    #ifdef ONLINE_JUDGE 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
