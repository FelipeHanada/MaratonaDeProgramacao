#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> seen(n, 0); // visitados
    stack<int> stk; // organiza a percussão
    vector<int> comps;
    for (int i=0; i<n; i++) {
        if (seen[i]) continue;

        comps.push_back(i);
        stk.push(i);
        seen[i] = 1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();

            for (int neighbor : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                stk.push(neighbor);
            }
        }
    }

    cout << comps.size() - 1 << '\n';
    for (int i=1; i<comps.size(); i++) {
        cout << comps[0] + 1 << ' ' << comps[i] + 1 << '\n';
    }
}