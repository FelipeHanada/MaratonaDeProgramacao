#include <bits/stdc++.h>
using namespace std;


#define _1 first
#define _2 second

constexpr int MAX_N = 2e5;

int n, m, q;

vector<pair<int, int>> neighbors(int i, int j) {
    vector<pair<int, int>> s;
    if (i) s.push_back({i-1, j});
    if (i<n-1) s.push_back({i+1, j});
    if (j) s.push_back({i, j-1});
    if (j<m-1) s.push_back({i, j+1});
    return s;
}

const size_t DSU_N = 4e5; // MAX_N*MAX_M + MAX_Q <= 4e5 
int parent[DSU_N], sz[DSU_N], val[DSU_N], important[DSU_N];

void make_set(int i, int v) {
    parent[i] = i;
    val[i] = v;
    sz[i] = 1;
    important[i] = 1;
}

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void union_set(int i, int j) {
    int pi = find(i), pj = find(j);
    if (pi == pj) return;

    if (sz[pi] < sz[pj]) swap(pi, pj);
    parent[pj] = pi;
    if (sz[pi] == sz[pj]) sz[pi]++;
    important[pi] = important[pi] & important[pj];
}

void solve() {
    cin >> n >> m;
    int grid[n][m];
    int id[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
            id[i][j] = i*m+j;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            make_set(id[i][j], grid[i][j]);
            for (auto &[p, q] : neighbors(i, j)) {
                if (grid[p][q] < grid[i][j]) important[id[i][j]] = 0;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (auto &[p, q] : neighbors(i, j)) {
                if (grid[i][j] == grid[p][q]) {
                    union_set(id[i][j], id[p][q]);
                }
            }
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (parent[id[i][j]] == id[i][j]) {
                ans += important[id[i][j]];
            }
        }
    }
    cout << ans << '\n';

    int new_id = n*m;
    cin >> q;
    while (q--) {
        int r, c, x;
        cin >> r >> c >> x;
        r--; c--;

        x = grid[r][c] - x;

        int small = INT32_MAX;
        set<int> s; // neighbor components
        for (const auto &[p, q] : neighbors(r, c)) {
            s.insert(find(id[p][q]));
            small = min(small, grid[p][q]);
        }
        s.insert(find(id[r][c]));

        for (auto &c : s) {
            ans -= important[c];
        }

        for (auto &y : s) {
            if (x < val[y]) {
                important[y] = 0;
                // y cannot be a sink
            }
        }

        make_set(new_id, x);
        if (small < x) important[new_id] = 0;

        for (auto &y : s) {
            if (val[y] == x) {
                union_set(new_id, y);
            }
        }

        grid[r][c] = x;
        id[r][c] = new_id++;

        s.clear(); // recompute neighboring components
        for (auto &[p, q] : neighbors(r, c)) {
            s.insert(find(id[p][q]));
        }
        s.insert(find(id[r][c]));

        for (auto &y : s) {
            ans += important[y];
        }

        cout << ans << '\n';
    }
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}