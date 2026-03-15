#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }

    map<int, int> dp;
    set<int> s;
    vector<bool> seen(n, 0);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [ rcost, curr ] = pq.top(); pq.pop();
        if (seen[curr]) continue;
        seen[curr] = 1;
        dp[curr] = -rcost;

        if (dp[curr] < curr) s.insert(curr);

        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            pq.push({ min(rcost, -curr), neighbor });
        }
    }

    stack<int> mono;
    for (int i=0; i<n; i++) {
        if (!dp.count(i)) dp[i] = INT32_MAX;

        int val = dp[i];
        if (!mono.empty()) {
            val = max(mono.top(), val);
        }

        mono.push(val);
    }

    multiset<int> ms;
    vector<int> ans(n);
    for (int i=n-1; i>=0; i--) {
        if (mono.top() > i) {
            ans[i] = -1;
        } else {
            // ans = number of vertices j > i with dp[j] <= i
            while (!ms.empty() && *ms.rbegin() > i) ms.erase(*ms.rbegin());
            ans[i] = ms.size();
        }

        ms.insert(dp[i]);
        mono.pop();
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << '\n';
    }
}
