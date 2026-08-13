#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int MAX_K = 500;

int n, k;
vector<vector<int>> adj;
ll dfs(int curr, int p, array<int,MAX_K+1>& dist) {
    ll ans = 0;
    fill(dist.begin(), dist.end(), 0); dist[0] = 1;
    vector<array<int,MAX_K+1>> children;
    for (int neighbor : adj[curr]) if (neighbor != p) {
        children.push_back(array<int,MAX_K+1>());
        array<int,MAX_K+1> &d = children.back();
        ans += dfs(neighbor, curr, d);

        for (int i=0; i<MAX_K; i++) dist[i+1] += d[i];
    }

    ans += dist[k];

    ll partial = 0;
    for (array<int, MAX_K+1> &d : children) {
        for (int a=1; a<k; a++) {
            int b = k-a;

            partial += (ll)d[a-1] * (dist[b] - d[b-1]);
        }
    }
    partial /= 2;

    return ans + partial;
}

int main() {
    cin >> n >> k;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    array<int, MAX_K+1> dist;
    cout << dfs(0, -1, dist) << '\n';
}

/*

*/
