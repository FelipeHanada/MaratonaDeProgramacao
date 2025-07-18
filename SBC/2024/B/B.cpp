#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + m);  // last n nodes are movies
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        for (int j=0; j<k; j++) {
            int x; cin >> x; x--;
            adj[m + i].push_back(x);
            adj[x].push_back(m + i);
        }
    }

    vector<int> roots;
    vector<int> components(n + m, -1);
    vector<pair<int, int>> paths(n + m, {-1, -1});
    int q;
    cin >> q;

    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y; x--; y--;

        if (components[x] < 0) {
            int curr_comp = roots.size();
            roots.push_back(x);
            components[x] = curr_comp;
            paths[x] = { x, 0 };

            queue<int> bfs;
            bfs.push(x);
            while (!bfs.empty()) {
                int curr = bfs.front(); bfs.pop();
                
                for (auto a : adj[curr]) {
                    if (components[a] >= 0) continue;
                    components[a] = curr_comp;
                    paths[a] = { curr, paths[curr].second + 1 };
                    bfs.push(a);
                }
            }
        }

        if (components[x] != components[y]) {
            cout << -1 << '\n';
            continue;
        }

        int component = components[x];
        int root = roots[component];
        // find a path from x to root[component] to y
        cout << (paths[x].second + paths[y].second) / 2 + 1 << '\n';

        int curr = x;
        bool actor = true;

        while (curr != root) {
            cout << curr + (actor ? 0 : -m) + 1 << ' ';
            curr = paths[curr].first;
            actor = !actor;
        }

        cout << root + 1 << ' ';
        
        stack<int> pathstack;
        curr = y;
        while (curr != root) {
            pathstack.push(curr);
            curr = paths[curr].first;
        }
        actor = false;
        while (!pathstack.empty()) {
            cout << pathstack.top() + (actor ? 0 : -m) + 1 << ' ';
            pathstack.pop();
            actor = !actor;
        }
        cout << '\n';
    }
}
