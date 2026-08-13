#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> c, ans;

set<int> dfs(int i, int p) {
    set<int> curr; curr.insert(c[i]);

    for (int neighbor : adj[i]) if (neighbor != p) {
        set<int> s = dfs(neighbor, i);

        if (curr.size() < s.size()) swap(curr, s);
        for (int x : s) curr.insert(x);
    }

    ans[i] = curr.size();

    return curr;
}

int main() {
    cin >> n;
    c.resize(n); adj.resize(n); ans.resize(n);
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
