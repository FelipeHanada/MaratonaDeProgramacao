#include <bits/stdc++.h>
using namespace std;


using ll = long long;


constexpr int MAX_N = 200000;
int c[MAX_N];
bool seen[MAX_N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) cin >> c[i];

    vector<vector<int>> adj(n);
    int l, r;
    for (int i=0; i<m; i++) {
        cin >> l >> r;
        l--; r--;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    int ans = 0;
    fill_n(seen, n, 0);
    stack<int> stk;
    for (int i=0; i<n; i++) if (!seen[i]) {
        stk.push(i);
        seen[i] = 1;

        unordered_map<int, int> m;
        int big = 0, total = 0;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();
            total++;
            big = max(big, ++m[c[curr]-1]);

            for (int neighbor : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                stk.push(neighbor);
            }
        }

        ans += total - big;
    }

    cout << ans << '\n';
}
