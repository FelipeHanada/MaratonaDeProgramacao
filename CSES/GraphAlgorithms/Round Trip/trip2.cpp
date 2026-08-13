#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

vector<bool> seen;
vector<int> parent;
int cycle_start, cycle_end;
bool dfs(int i, int par) {
    seen[i] = 1;
    for (int neighbor : adj[i]) {
        if (neighbor == par) continue;
        if (seen[neighbor]) {
            cycle_end = i;
            cycle_start = neighbor;
            return 1;
        }

        parent[neighbor] = i;
        if (dfs(neighbor, i)) return 1;
    }

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
        adj[y].push_back(x);
    }

    seen.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = cycle_end = -1;
    for (int i=0; i<n; i++) if (!seen[i] && dfs(i, -1)) break;


    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;

        cycle.push_back(cycle_start);
        for (int i=cycle_end; i!=cycle_start; i=parent[i]) cycle.push_back(i);
        cycle.push_back(cycle_start);

        cout << cycle.size() << '\n';
        for (int x : cycle) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}