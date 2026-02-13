#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // vector<int> deg(n, -1); deg[0] = 0;
    // for (int i=0; i<n; i++) {
    //     deg[i] += adj[i].size();
    // }
    vector<int> childs(n, 0);
    vector<int> parent(n, -1);
    queue<int> bfs; bfs.push(0);
    while (!bfs.empty()) {
        auto curr = bfs.front(); bfs.pop();
        for (int neighbor : adj[curr]) if (neighbor != parent[curr]) {
            parent[neighbor] = curr;
            childs[curr]++;
            bfs.push(neighbor);
        }
    }

    auto check = [&](int x) -> bool {
        vector<int> c(n);
        queue<int> q;
        for (int i=0; i<n; i++) {
            c[i] = childs[i];
            if (c[i] == 0) q.push(i);
        }
        vector<int> size(n, 1);
        int comps = 0;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            if (size[curr] >= x) comps++;
            else if (parent[curr] >= 0) size[parent[curr]] += size[curr];

            if (parent[curr] >= 0 && !(--c[parent[curr]])) {
                q.push(parent[curr]);
            }
        }

        return comps >= k + 1;
    };

    int l = 1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
