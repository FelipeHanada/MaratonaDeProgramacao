#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 2e5;
int n, k;
vector<int> adj[MAX_N];
int sz[MAX_N];

ll dfs(int v, int p) {
    sz[v] = 1;

    ll ans = 1; // v \in Sv

    for (int neighbor : adj[v]) {
        if (neighbor == p) continue;
        ans += dfs(neighbor, v);

        // v \in Su for any u inside this subtree
        if (n - sz[neighbor] >= k) {
            ans += sz[neighbor];
        }

        sz[v] += sz[neighbor];
    }

    if (sz[v] >= k) {
        ans += n - sz[v];
    }

    return ans;
}

void solve() {
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(0, -1) << '\n';

    for (int i=0; i<n; i++) {
        adj[i].clear();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
