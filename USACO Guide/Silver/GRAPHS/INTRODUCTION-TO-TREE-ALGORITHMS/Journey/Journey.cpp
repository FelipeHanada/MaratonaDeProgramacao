#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100000;
int n;
vector<int> adj[MAX_N];

double ans = 0;
void dfs(int v, int p, int h, double prob) {
    int children = 0;
    for (int x : adj[v]) {
        if (x == p) continue;
        children++;
    }

    if (children == 0) {
        ans += h * prob;
    } else {
        const double new_prob = prob / children;
        for (int x : adj[v]) {
            if (x == p) continue;
            dfs(x, v, h + 1, new_prob);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, 0, 1);
    cout << setprecision(10) << ans << endl;
}
