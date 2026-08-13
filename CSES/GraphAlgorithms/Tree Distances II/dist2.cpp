#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int n;
vector<vector<int>> adj;
vector<ll> sizes, sum;
void dfs1(int curr, int p) {
    sizes[curr] = 1;
    sum[curr] = 0;
    for (int neighbor : adj[curr]) if (neighbor != p) {
        dfs1(neighbor, curr);
        sizes[curr] += sizes[neighbor];
        sum[curr] += sum[neighbor] + sizes[neighbor];
    }
}
vector<ll> ans;
void dfs2(int curr, int p) {
    ans[curr] = sum[curr];
    for (int neighbor : adj[curr]) if (neighbor != p) {
        auto prev_curr = make_tuple(sizes[curr], sum[curr]);
        auto prev_neighbor = make_tuple(sizes[neighbor], sum[neighbor]);

        sizes[curr] -= sizes[neighbor];
        sum[curr] -= sum[neighbor] + sizes[neighbor];
        sizes[neighbor] += sizes[curr];
        sum[neighbor] += sum[curr] + sizes[curr];

        dfs2(neighbor, curr);

        tie(sizes[curr], sum[curr]) = prev_curr;
        tie(sizes[neighbor], sum[neighbor]) = prev_neighbor;
    }
}
/*
  o
 / \
o   o
|\
o o
*/


int main() {
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sizes.resize(n);
    sum.resize(n);
    ans.resize(n);
    dfs1(0, -1);
    dfs2(0, -1);

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}
