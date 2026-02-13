#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vector<bool> problem(n, 0);
    vector<int> parent(n);
    stack<int> stk; stk.push(0);
    vector<bool> seen(n, 0); seen[0] = 1;
    while (!stk.empty()) {
        auto curr = stk.top(); stk.pop();
        for (auto [neighbor, p] : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = 1;
            parent[neighbor] = curr;
            if (p) problem[neighbor] = 1;
            stk.push(neighbor);
        }
    }

    vector<int> deg(n, 0);
    queue<int> q;
    for (int i=1; i<n; i++) {
        deg[i] = adj[i].size() - 1;
        if (deg[i] == 0) q.push(i);
    }

    set<int> ans;
    vector<int> used(n, 0);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        if (curr == 0) continue;

        if (problem[curr] && !used[curr]) {
            ans.insert(curr);
            used[curr] = 1;
        }

        if (used[curr]) used[parent[curr]] = 1;

        if (--deg[parent[curr]] == 0) {
            q.push(parent[curr]);
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}