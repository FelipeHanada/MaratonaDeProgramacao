#include <bits/stdc++.h>
using namespace std;

/*
Interpret the grid as a graph.
An edge uv \in E(G) iff. u and v are adjacent (by the problem def.)
    and value of u = value of v.

For the minimum number of sinks to be placed
    we can place one sink in each connected component such that
        all neighbor connected components have value larger than this

*/

int n, m, q, r, c, x;

vector<pair<int, int>> neighbors(int i, int j) {
    vector<pair<int, int>> s;
    if (i > 0) s.push_back({i-1, j});
    if (j > 0) s.push_back({i, j-1});
    if (i + 1 < n) s.push_back({i+1, j});
    if (j + 1 < m) s.push_back({i, j+1});
    return s;
}

constexpr int N = 4e5;
int parent[N], sz[N], val[N], sink[N];
    // DSU | vertex's value | if the connected component of the vertex must have a sink

void make_set(int i, int v) {
    parent[i] = i;
    sz[i] = 1;
    val[i] = v;
    sink[i] = 1;
}

int find(int i) {
    int pi = i;
    while (parent[pi] != pi) pi = parent[pi];
    return parent[i] = pi;
}

void union_set(int i, int j) {
    int pi = find(i), pj = find(j);
    if (pi == pj) return;
    if (sz[pi] < sz[pj]) swap(pi, pj);
    parent[pj] = pi;
    if (sz[pi] == sz[pj]) sz[pi]++;
    sink[pi] &= sink[pj];
        // since pi and pj are in the same CC, one can be a sink iff. the other is can be a sink
}


void solve() {
    cin >> n >> m;
    int grid[n][m];  // cell's (i,j) current value
    int id[n][m];  // cell's (i,j) vertex num.
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
                if (grid[p][q] < grid[i][j]) sink[id[i][j]] = 0;
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
            if (parent[id[i][j]] == id[i][j])
                ans += sink[id[i][j]];
        }
    }

    cout << ans << '\n';

    int new_id = n*m;

    cin >> q;
    while (q--) {
        cin >> r >> c >> x;
        r--; c--;
        x = grid[r][c] - x;

        set<int> s; // neighboring CCs
        for (auto &[p, q] : neighbors(r, c)) {
            s.insert(find(id[p][q]));
        }
        s.insert(find(id[r][c]));
        
        for (auto c : s) {
            ans -= sink[c];
        }

        make_set(new_id, x);
        for (auto c : s) {
            if (val[c] < x) sink[new_id] = 0;
            else if (val[c] > x) sink[c] = 0;
        }

        for (auto c : s) {
            if (val[c] == x) union_set(new_id, c);
        }

        grid[r][c] = x;
        id[r][c] = new_id++;

        s.clear();
        for (auto &[p, q] : neighbors(r, c)) {
            s.insert(find(id[p][q]));
        }
        s.insert(find(id[r][c]));

        for (auto c : s) {
            ans += sink[c];
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