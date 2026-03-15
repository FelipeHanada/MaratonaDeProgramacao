#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    while (n || m) {
        vector<set<int>> adj(n);
        vector<array<int,2>> edges(m);
        for (int i=0; i<m; i++) {
            cin >> edges[i][0] >> edges[i][1];
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }


        bool ans = 0;
        for (int i=0; !ans && i<m; i++) {
            adj[edges[i][0]].erase(edges[i][1]);
            adj[edges[i][1]].erase(edges[i][0]);

            stack<int> dfs; dfs.push(0);
            vector<bool> seen(n, 0); seen[0] = 1;
            int rem = n;
            
            while (!dfs.empty()) {
                auto curr = dfs.top(); dfs.pop();
                rem--;

                for (int neighbor : adj[curr]) {
                    if (seen[neighbor]) continue;
                    seen[neighbor] = 1;
                    dfs.push(neighbor);
                }
            }

            ans = rem;

            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        cout << (ans ? "Yes" : "No") << '\n';

        cin >> n >> m;
    }
}