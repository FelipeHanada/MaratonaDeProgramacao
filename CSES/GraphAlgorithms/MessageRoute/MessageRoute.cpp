#include <bits/stdc++.h>
using namespace std;


void print_path(pair<int, int> d[], int curr) {
    if (d[curr].first != 0)
        print_path(d, d[curr].second);
    
    cout << curr + 1 << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    bool seen[n]; fill_n(seen, n, false);
    pair<int, int> d[n];
    
    for (int i=0; i<n; i++)
        d[i] = {INT32_MAX - 1, 0};
    d[0] = {0, 0};

    queue<int> s; s.push(0);
    while (!s.empty()) {
        int curr = s.front(); s.pop();
        if (seen[curr]) continue;
        seen[curr] = true;

        for (auto it = adj[curr].begin(); it != adj[curr].end(); it++) {
            if (d[curr].first + 1 < d[*it].first) {
                d[*it] = {d[curr].first + 1, curr};
            }

            s.push(*it);
        }
    }

    if (d[n-1].first == INT32_MAX - 1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << d[n-1].first + 1 << "\n";
        print_path(d, n - 1);
    }
    cout << "\n";
}
