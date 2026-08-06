#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }

vector<int> color;
vector<vector<int>> adj;
array<int,3> dfs(int curr, int p) {
    array<int,3> a;
    if (color[curr] == 0) a = { 1, 0, 0 };
    else if (color[curr] == 1) a = { 0, 1, 0 };
    else if (color[curr] == 2) a = { 0, 0, 1 };
    else a = { 1, 1, 1 };

    for (int neighbor : adj[curr]) if (neighbor != p) {
        array<int,3> b = dfs(neighbor, curr);
        a[0] = mult(a[0], add(b[1], b[2]));
        a[1] = mult(a[1], add(b[0], b[2]));
        a[2] = mult(a[2], add(b[0], b[1]));
    }

    return a;
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int n, k; cin >> n >> k;
    color.assign(n, -1);
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=0; i<k; i++) {
        int x, y; cin >> x >> y; x--; y--;
        color[x] = y;
    }
    
    auto [ a0, a1, a2 ] = dfs(0, -1);
    cout << add(add(a0, a1), a2) << '\n';
}