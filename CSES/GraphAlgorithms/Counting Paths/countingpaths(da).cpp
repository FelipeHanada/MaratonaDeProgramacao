#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> adj;
vector<int> parent, depth, heavy;
int dfs(int i) {
    int size = 1;
    pair<int, int> h = { -1, -1 };
    for (int j : adj[i]) if (j != parent[i]) {
        parent[j] = i;
        depth[j] = depth[i] + 1;

        int c_size = dfs(j);
        size += c_size;
        h = max(h, { c_size, j });
    }
    heavy[i] = h.second;
    return size;
}

int curr_pos;
vector<int> head, pos;
void decompose(int i, int h) {
    head[i] = h; pos[i] = curr_pos++;
    if (heavy[i] != -1) decompose(heavy[i], h);
    for (int j : adj[i]) if (j != parent[i] && heavy[i] != j) {
        decompose(j, j);
    }
}

vector<int> diff;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent.resize(n); parent[0] = -1;
    depth.resize(n); depth[0] = 0;
    heavy.assign(n, -1);
    dfs(0);

    curr_pos = 0;
    head.resize(n);
    pos.resize(n);
    decompose(0, 0);

    diff.assign(n+1, 0);
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y; x--; y--;

        for (; head[x] != head[y]; y = parent[head[y]]) {
            if (depth[head[x]] > depth[head[y]]) swap(x, y);
            diff[pos[head[y]]]++;
            diff[pos[y]+1]--;
        }

        if (depth[x] > depth[y]) swap(x, y);
        diff[pos[x]]++;
        diff[pos[y]+1]--;
    }

    for (int i=1; i<=n; i++) diff[i] += diff[i-1];

    for (int i=0; i<n; i++) cout << diff[pos[i]] << ' ';
    cout << '\n';
}