#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> in(n, 0);
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        in[b-1]++;
    }

    queue<int> q;
    for (int i=0; i<n; i++) if (in[i] == 0) q.push(i);

    vector<int> ts;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ts.push_back(curr);
        for (int neighbor : adj[curr]) {
            in[neighbor]--;
            if (in[neighbor] == 0) q.push(neighbor);
        }
    }

    if (ts.size() < n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i : ts) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}