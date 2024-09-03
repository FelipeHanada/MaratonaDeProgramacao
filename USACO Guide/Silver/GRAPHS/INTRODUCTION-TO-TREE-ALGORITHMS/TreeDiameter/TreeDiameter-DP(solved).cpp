#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 2e5;
vector<int> adj[MAX_N];
int dp[MAX_N];
int diameter = INT32_MIN;

void max_distance_to_leaf(int v, int p) {
    int d_to_leaf = 0;
    int d1 = -1, d2 = -1;

    for (int x : adj[v]) {
        if (x == p) continue;
    
        max_distance_to_leaf(x, v);
        d_to_leaf = max(d_to_leaf, dp[x] + 1);
    
        if (dp[x] > d1) {
            d2 = d1;
            d1 = dp[x];
        } else if (dp[x] > d2) {
            d2 = dp[x];
        }
    }

    dp[v] = d_to_leaf;
    diameter = max(diameter, 2 + d1 + d2);
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    max_distance_to_leaf(0, -1);
    cout << diameter << endl;
}
