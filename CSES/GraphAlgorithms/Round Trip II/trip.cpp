#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> adj;
vector<bool> seen;
vector<bool> in_stack;
vector<int> cycle;
bool dfs(int i) {
    seen[i] = in_stack[i] = 1;
    for (int next : adj[i]) {
        if (in_stack[next]) {
            cycle.push_back(next);
            cycle.push_back(i);
            return 1;
        }
        
        if (seen[next]) continue;
        if (dfs(next)) {
            cycle.push_back(i);
            return i != cycle.front();
        }

        if (!cycle.empty()) return 0;
    }
    in_stack[i] = 0;
    return 0;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }
    
    cycle = vector<int>();
    seen = vector<bool>(n, 0);
    in_stack = vector<bool>(n, 0);
    for (int i=0; i<n && cycle.empty(); i++) {
        if (seen[i]) continue;
        dfs(i);
    }

    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << '\n';
        reverse(cycle.begin(), cycle.end());
        for (int x : cycle) cout << x + 1 << ' ';
        cout << '\n';
    }
}