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

int n;
vector<vector<int>> adj;
pair<int, int> dfs(int curr, int p) {
    int ans0, ans1;
    ans0 = 1, ans1 = 1;

    for (int neighbor : adj[curr]) if (neighbor != p) {
        auto [ x, y ] = dfs(neighbor, curr);
        ans0 = mult(ans0, add(x, y));
        ans1 = mult(ans1, x);
    }

    return { ans0, ans1 };
}

int main() {
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto [ ans0, ans1 ] = dfs(0, -1);
    cout << add(ans0, ans1) << '\n';
}
