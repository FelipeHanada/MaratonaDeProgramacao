#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> bat(n);
    for (int i=0; i<n; i++) cin >> bat[i];

    int W = 0;
    vector<vector<pair<int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        s--; t--;
        adj[s].push_back({t, w});
        W = max(W, w);
    }

    int l = -1, r;
    {
        vector<int> dp(n, -1);
        // dp[i] = maximum number of batteries that we can get at vertex i
        
        stack<pair<int, int>> stk;
        stk.push({min(W, bat[0]), 0});
        while (!stk.empty()) {
            auto [b, curr] = stk.top();
            stk.pop();
            if (dp[curr] >= b) continue;
            dp[curr] = b;
            for (auto &[t, w] : adj[curr]) if (b >= w) {
                stk.push({min(W, b + bat[t]), t});
            }
        }

        if (dp[n-1] == -1) {
            cout << "-1\n";
            return;
        } else {
            r = dp[n-1];
        }
    }

    while (r - l > 1) {
        int mid = (l + r) / 2;

        vector<int> dp(n, -1);
        // dp[i] = maximum number of batteries that we can get at vertex i
        
        stack<pair<int, int>> stk;
        stk.push({min(mid, bat[0]), 0});
        while (!stk.empty()) {
            auto [b, curr] = stk.top();
            stk.pop();
            if (dp[curr] >= b) continue;
            dp[curr] = b;
            for (auto &[t, w] : adj[curr])
                if (b >= w) {
                stk.push({min(mid, b + bat[t]), t});
            }
        }

        if (dp[n-1] == -1) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << r << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}