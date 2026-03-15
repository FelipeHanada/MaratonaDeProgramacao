#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }

    set<int> v;
    for (int i=0; i<n; i++) v.insert(i);
    for (int i=0; i<n; i++) {
        stack<int> stk; stk.push(*v.begin());
        vector<bool> seen(n, 0); seen[*v.begin()] = 1;
        int size = 1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();
            for (int neighbor : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                size++;
                stk.push(neighbor);
            }
        }

        cout << (size == n - i ? "YES" : "NO") << '\n';

        for (int j=0; j<n; j++) {
            adj[j].erase(a[i]);
        }
        v.erase(a[i]);
    }
}