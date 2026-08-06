#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> adj;
vector<int> height;
void dfs1(int curr, int p) {
    height[curr] = 0;
    for (int neighbor : adj[curr]) if (neighbor != p) {
        dfs1(neighbor, curr);
        height[curr] = max(height[curr], height[neighbor] + 1);
    }
}
vector<int> ans;
void dfs2(int curr, int p) {
    ans[curr] = height[curr];

    int big1 = -1, big2 = -1;
    for (int neighbor : adj[curr]) {
        if (height[neighbor] > big1) {
            big2 = big1;
            big1 = height[neighbor];
        } else if (height[neighbor] > big2) {
            big2 = height[neighbor];
        }
    }

    for (int neighbor : adj[curr]) if (neighbor != p) {
        int h_curr_prev = height[curr],
            h_neighbor_prev = height[neighbor];
        if (height[neighbor] == big1) {
            height[curr] = big2 + 1;
            height[neighbor] = max(height[neighbor], height[curr] + 1);
        } else {
            height[curr] = big1 + 1;
            height[neighbor] = max(height[neighbor], height[curr] + 1);
        }

        dfs2(neighbor, curr);

        height[curr] = h_curr_prev;
        height[neighbor] = h_neighbor_prev;
    }
}
/*
  o
 /
o
| \
o  o
*/

int main() {
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; ++i) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    height.resize(n);
    ans.resize(n);
    dfs1(0, -1);
    dfs2(0, -1);

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
