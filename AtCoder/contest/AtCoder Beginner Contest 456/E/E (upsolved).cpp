#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m, w;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges.push_back({ x, y });
        edges.push_back({ y, x });
    }
    for (int i=0; i<n; i++) edges.push_back({ i, i });

    cin >> w;
    vector<string> h(n);
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }

    auto node = [&](int i, int j) -> int { return w*i + j; };

    vector<vector<int>> adj(n*w);
    for (auto [x, y] : edges) {
        for (int i=0; i<w-1; i++) if (h[x][i] == 'o' && h[y][i+1] == 'o') {
            adj[node(x, i)].push_back(node(y, i+1));
        }

        if (h[x][w-1] == 'o' && h[y][0] == 'o') {
            adj[node(x, w-1)].push_back(node(y, 0));
        }
    }


    vector<int> color(n*w, 0);
    function<bool(int)> find_cycle;
    find_cycle = [&](int i) -> bool {
        color[i] = 1;

        for (int neighbor : adj[i]) {
            if (color[neighbor] == 0) {
                if (find_cycle(neighbor)) return 1;
            } else if (color[neighbor] == 1) {
                return 1;
            }
        }

        color[i] = 2;
        return 0;
    };


    bool cycle = 0;
    for (int i=0; i<n*w; i++) if (color[i] == 0) {
        cycle = cycle || find_cycle(i);
    }

    cout << (cycle ? "Yes" : "No") << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}