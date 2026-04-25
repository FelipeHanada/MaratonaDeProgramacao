#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
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

    vector<bool> seen(n, 0);
    {
        stack<int> dfs;
        dfs.push(0);
        while (!dfs.empty()) {
            auto curr = dfs.top(); dfs.pop();
            for (int neighbor : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                dfs.push(neighbor);
            }
        }

        if (count(seen.begin(), seen.end(), false)) {
            cout << "NO\n";
            return 0;
        }
    }


    vector<int> cycle;
    seen.assign(n, 0);
    for (int i=0; i<n && cycle.empty(); i++) if (!seen[i]) {
        stack<array<int,3>> dfs;
        dfs.push({i, 1, -1});
        vector<bool> in_stk(n, 0);
        while (!dfs.empty() && cycle.empty()) {
            auto [curr, state, p] = dfs.top(); dfs.pop();
            if (seen[curr]) continue;

            if (state) {
                dfs.push({curr, 0});
                seen[curr] = 1;
                in_stk[curr] = 1;

                for (int neighbor : adj[curr]) if (p != neighbor) {
                    if (in_stk[neighbor]) {
                        while (dfs.top()[1]) dfs.pop();
                        while (!dfs.empty() && dfs.top()[0] != neighbor) {
                            cycle.push_back(dfs.top()[0]);
                            dfs.pop();
                            while (!dfs.empty() && dfs.top()[1]) dfs.pop();
                        }
                        cycle.push_back(neighbor);
                    }

                    if (seen[neighbor]) continue;
                    dfs.push({neighbor, 1, curr});
                }

            } else {
                in_stk[curr] = 0;
            }
        }
    }


    if (cycle.empty()) {
        cout << "NO\n";
        return 0;
    }

    seen.assign(n, 0);
    for (int x : cycle) seen[x] = 1;

    cycle.clear();
    for (int i=0; i<n && cycle.empty(); i++) if (!seen[i]) {
        stack<array<int,3>> dfs;
        dfs.push({i, 1, -1});
        vector<bool> in_stk(n, 0);
        while (!dfs.empty() && cycle.empty()) {
            auto [curr, state, p] = dfs.top(); dfs.pop();
            if (seen[curr]) continue;

            if (state) {
                dfs.push({curr, 0});
                seen[curr] = 1;
                in_stk[curr] = 1;

                for (int neighbor : adj[curr]) if (p != neighbor) {
                    if (in_stk[neighbor]) {
                        while (dfs.top()[1]) dfs.pop();
                        while (!dfs.empty() && dfs.top()[0] != neighbor) {
                            cycle.push_back(dfs.top()[0]);
                            dfs.pop();
                            while (!dfs.empty() && dfs.top()[1]) dfs.pop();
                        }
                        cycle.push_back(neighbor);
                    }

                    if (seen[neighbor]) continue;
                    dfs.push({neighbor, 1, curr});
                }

            } else {
                in_stk[curr] = 0;
            }
        }
    }

    if (cycle.empty()) {
        cout << "FHTAGN!\n";
    } else {
        cout << "NO\n";
    }
}
