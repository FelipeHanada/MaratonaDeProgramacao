#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return ((ll)a * b) % md;
}

int n, k;
int ans;
int powern[101];

int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        b >>= 1;
        a = mult(a, a);
    }
    return ans;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cin >> n >> k;
    vector<vector<array<int,2>>> adj(n);
    vector<array<int,3>> edges(n-1);
    for (int i=0; i<n-1; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--; edges[i][1]--;

        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    powern[0] = 1;
    for (int i=1; i<=k; i++) powern[i] = mult(powern[i-1], n);

    vector<int> d(n, 0); // maior componente conexa só de arestas 0
    vector<bool> seen(n, 0);
    for (int i=0; i<n; i++) {
        if (seen[i]) continue;

        vector<int> x;
        stack<int> stk; stk.push(i);
        seen[i] = 1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();
            x.push_back(curr);
            d[i]++;

            for (auto [neighbor, cost] : adj[curr]) {
                if (cost || seen[neighbor]) continue;
                seen[neighbor] = 1;
                stk.push(neighbor);
            }
        }

        for (int y : x) d[y] = d[i];
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = add(ans, powern[k-1]);
        ans = add(ans, -binpow(d[i], k-1));
    }
    cout << ans << '\n';
}