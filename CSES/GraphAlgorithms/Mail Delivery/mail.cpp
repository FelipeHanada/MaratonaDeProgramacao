#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<unordered_multiset<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    for (int i=0; i<n; i++) {
        if (adj[i].size() & 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> ans;
    stack<int> stk;
    stk.push(0);
    while (!stk.empty()) {
        auto curr = stk.top();
        if (!adj[curr].size()) {
            ans.push_back(curr);
            stk.pop();
        } else {
            auto next = *adj[curr].begin();
            adj[curr].extract(next);
            adj[next].extract(curr);
            stk.push(next);
        }
    }

    if (ans.size() - 1 < m) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}