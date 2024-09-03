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

    set<int> central_cities;
    pair<int, int> no_travel_cities;
    for (int city=0; city<n; city++) {
        bool connected_to_central_city = false;

        set<int> seen; seen.insert(city);
        stack<int> dfs; dfs.emplace(city);

        while (dfs.size() > 0 && !connected_to_central_city) {
            int curr = dfs.top(); dfs.pop();

            set<int> adj_unseen;
            set_difference(adj[curr].begin(), adj[curr].end(), seen.begin(), seen.end(), inserter(adj_unseen, adj_unseen.begin()));
            for (int x : adj_unseen) {
                if (central_cities.find(x) != central_cities.end()) {
                    connected_to_central_city = true;
                    break;
                }

                seen.insert(x);
                dfs.emplace(x);
            }
        }

        if (connected_to_central_city || seen.size() == n) {
            central_cities.insert(city);
        } else {
            int j = 0;
            for (; j<n && seen.find(j) != seen.end(); j++) {
            }
            no_travel_cities = {city, j};
            break;
        }
    }

    if (central_cities.size() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        cout << no_travel_cities.first + 1 << " " << no_travel_cities.second + 1 << endl;
    }
}
