#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    vector<vector<int>> adj(n);
    for (int i=1; i<n; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> parent(n);
    vector<vector<int>> childs(n);
    queue<pair<int, int>> bfs; bfs.push({ 0, -1 });
    while (!bfs.empty()) {
        auto [ curr, p ] = bfs.front(); bfs.pop();
        
        parent[curr] = p;
        for (int neighbor : adj[curr]) if (neighbor != p) {
            childs[curr].push_back(neighbor);
            bfs.push({ neighbor, curr });
        }
    }
    
    vector<ll> height(n, 0), sum(n, 0);
    vector<ll> dp0(n), dp1(n);
    vector<int> deg(n, 0);
    for (int i=0; i<n; i++) deg[i] = childs[i].size();
    queue<int> q;
    for (int i=0; i<n; i++) if (!deg[i]) q.push(i);
        
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
    
        sum[curr] += a[curr];
        if (parent[curr] != -1) {
            height[parent[curr]] = max(height[parent[curr]], height[curr] + 1);
            sum[parent[curr]] += sum[curr];
        }
        
        // its always optimal to move an entire subtree of a children of curr
        multiset<int> ms;
        for (int c : childs[curr]) ms.insert(height[c]);
        
        if (ms.empty()) {
            dp0[curr] = dp1[curr] = 0;
        } else if (ms.size() == 1) {
            dp0[curr] = dp0[childs[curr][0]] + sum[childs[curr][0]];
            dp1[curr] = dp1[childs[curr][0]] + sum[childs[curr][0]];
        } else {
            dp0[curr] = 0;
            for (int c : childs[curr]) dp0[curr] += dp0[c] + sum[c];
            
            dp1[curr] = dp0[curr];
            for (int c : childs[curr]) {
                ms.extract(height[c]);
                
                dp1[curr] = max(dp1[curr], dp0[curr] + ((*ms.rbegin()) + 1) * sum[c]);
                dp1[curr] = max(dp1[curr], dp0[curr] - dp0[c] + dp1[c]);
                
                ms.insert(height[c]);
            }
        }
        
        if (parent[curr] != -1 && !(--deg[parent[curr]])) q.push(parent[curr]);
    }
    
    for (int i=0; i<n; i++) cout << dp1[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) solve();
}
