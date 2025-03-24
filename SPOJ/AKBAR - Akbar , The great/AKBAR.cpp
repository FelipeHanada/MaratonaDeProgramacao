#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int test=0; test<t; test++) {
        int n, r, m;
        cin >> n >> r >> m;
 
        vector<vector<int>> adj(n);
        for (int i=0; i<r; i++) {
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        bool ans = true;
        vector<bool> prot(n, false);
        int protn = 0;
        for (int i=0; i<m; i++) {
            int k, s;
            cin >> k >> s;
            if (!ans) continue;

            vector<bool> seen(n, false);
            queue<pair<int, int>> q;
            q.emplace((pair<int, int>){k-1, 0});
            while (!q.empty()) {
                pair<int, int> curr = q.front(); q.pop();
                
                if (seen[curr.first]) continue;
                seen[curr.first] = true;

                if (prot[curr.first]) {
                    ans = false;
                    break;
                }
                prot[curr.first] = true;
                protn++;

                if (curr.second < s) {
                    for (auto it = adj[curr.first].begin(); it != adj[curr.first].end(); it++) {
                        if (seen[*it]) continue;
                        q.emplace((pair<int, int>){ *it, curr.second + 1 });
                    }
                }
            }
        }

        cout << ((ans && protn == n) ? "Yes" : "No") << "\n";
    }
}