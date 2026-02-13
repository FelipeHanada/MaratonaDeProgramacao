#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<multiset<int>> adj(n);
    vector<int> in_deg(n, 0), out_deg(n, 0);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        out_deg[x]++;
        in_deg[y]++;
    }
    adj[n-1].insert(0);
    out_deg[n-1]++;
    in_deg[0]++;

    for (int i=0; i<n; i++) {
        if (out_deg[i] != in_deg[i]) {
            cout << "IMPOSSIBLE\n";
            return 0; // graph is not eulerian
        }
    }

    vector<int> ans;
    stack<int> stk;
    stk.push(0);
    while (!stk.empty()) {
        auto curr = stk.top();
        if (adj[curr].empty()) {
            ans.push_back(curr);
            stk.pop();
        } else {
            auto next = *adj[curr].begin();
            adj[curr].extract(next);
            stk.push(next);
        }
    }
    
    ans.pop_back();
    if (ans.size() - 1 < m) {
        cout << "IMPOSSIBLE\n";
        return 0; // graph is disconnected
    }

    int start = 0;
    while (ans[start%ans.size()] != 0 || ans[(start+1)%ans.size()] != n-1) start++;

    cout << ans[start] + 1 << ' ';
    for (int i=(start-1+ans.size())%ans.size(); i!=start; i = (i-1+ans.size())%ans.size()) {
        cout << ans[i] + 1 << ' ';
    }

    cout << '\n';
}
