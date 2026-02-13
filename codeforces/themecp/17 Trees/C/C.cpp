#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}
int mult(int a, int b) {
    return ((ll)a * b) % md;
}

int n, k;
int ans;
int powern[101];
void sol(const vector<vector<int>> &d, int last, int chosen) {
    if (chosen == k) return;

    for (int i=0; i<n; i++) {
        // n^(n - chosen + 1)
        if (d[last][i]) {
            ans = add(ans, powern[k-chosen-1]);
        }
        else sol(d, i, chosen + 1);
    }
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

    vector<vector<int>> d(n, vector<int>(n, 1));
    for (int i=0; i<n; i++) {
        d[i][i] = 0;
        stack<int> stk; stk.push(i);
        vector<bool> seen(n, 0); seen[i] = 1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();

            for (auto [neighbor, cost] : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                d[i][neighbor] = d[i][curr] + cost;
                stk.push(neighbor);
            }
        }
    }

    for (int i=0; i<n; i++) {
        sol(d, i, 1);
    }
    cout << ans << '\n';
}