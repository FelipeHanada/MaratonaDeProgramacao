#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n, set<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
    }

    bool ok = true;
    pair<int, int> no_travel_cities;
    for (int city=0; city<n; city++) {
        set<int> seen; seen.insert(city);
        stack<int> dfs; dfs.emplace(city);

        while (dfs.size() > 0) {
            int curr = dfs.top(); dfs.pop();

            set<int> adj_unseen;
            set_difference(adj[curr].begin(), adj[curr].end(), seen.begin(), seen.end(), inserter(adj_unseen, adj_unseen.begin()));
            for (int x : adj_unseen) {
                seen.insert(x);
                dfs.emplace(x);
            }
        }

        if (seen.size() < n) {
            int j = 0;
            for (; j<n && seen.find(j) != seen.end(); j++) {
            }
            ok = false;
            no_travel_cities = {city, j};
            break;
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        cout << no_travel_cities.first + 1 << " " << no_travel_cities.second + 1 << endl;
    }
}
