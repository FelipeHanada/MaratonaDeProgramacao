#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;
vector<int> cycle;

bool dfs(int i) {
    color[i] = 1;

    for (int neighbor : adj[i]) {
        if (color[neighbor] == 1) {
            cycle_end = i;
            cycle_start = neighbor;
            return 1;            
        } else if (color[neighbor] == 0) {
            parent[neighbor] = i;
            if (dfs(neighbor)) return 1;            
        }
    }

    color[i] = 2;
    return 0;
}

int main() {
    cin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }

    color.assign(n, 0);
    parent.resize(n);
    cycle_start = cycle_end = -1;
    for (int i=0; i<n; i++)
        if (color[i] == 0 && dfs(i)) break;
    

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cycle.push_back(cycle_start);
        for (int i=cycle_end; i != cycle_start; i = parent[i])
            cycle.push_back(i);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << '\n';
        for (int x : cycle) cout << x + 1 << ' ';
        cout << '\n';
    }
}