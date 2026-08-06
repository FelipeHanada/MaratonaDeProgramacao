#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> sizes;
void dfs1(int i, int p) {
    sizes[i] = 1;
    for (int j : adj[i]) if (j != p) {
        dfs1(j, i);
        sizes[i] += sizes[j];
    } 
}

int ans;
void dfs2(int i, int p) {
    bool is_centroid = 1;

    for (int j : adj[i]) is_centroid = is_centroid && (sizes[j] <= n/2);
    if (is_centroid) ans = i;

    for (int j : adj[i]) if (j != p) {
        sizes[i] -= sizes[j];
        sizes[j] += sizes[i];
        dfs2(j, i);
        sizes[j] -= sizes[i];
        sizes[i] += sizes[j];
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sizes.resize(n);
    dfs1(0, -1);
    dfs2(0, -1);

    cout << ans + 1 << '\n';
}
