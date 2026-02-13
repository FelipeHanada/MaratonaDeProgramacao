#include <bits/stdc++.h>
using namespace std;


/*
3 -> 3 -> 6 -> 9

*/

void precompute() {

}

constexpr int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }

    int ans = 0;
    map<pair<int, int>, int> dp;


    auto cmp = [&](int i, int j) {
        return v[i] < v[j];
    };
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 0);
    sort(vertices.begin(), vertices.end(), cmp);

    for (int ii : vertices) {
        for (int nbb : adj[ii]) {
            stack<array<int, 3>> stk;
            stk.push({nbb, v[ii], 0});
            while (!stk.empty()) {
                auto [i, val, mark] = stk.top();
                stk.pop();
                if (dp.count({i, val})) continue;

                if (!mark) {
                    stk.push({i, val, 1});

                    for (auto nb : adj[i]) {
                        if (val + v[i] == v[nb]) {
                            stk.push({nb, v[i], 0});
                        }
                    }
                } else {
                    int p = 0;
                    for (auto nb : adj[i]) {
                        if (val + v[i] == v[nb]) {
                            p = (p + 1 + dp[{nb, v[i]}]) % MOD;
                        }
                    }
                    dp[{i, val}] = p;
                }
            }


            ans = (ans + 1 + dp[{nbb, v[ii]}]) % MOD;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}