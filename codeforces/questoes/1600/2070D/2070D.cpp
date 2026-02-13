#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> children(n);
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        children[p-1].push_back(i);
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    queue<int> curr, next;
    for (int child : children[0]) {
        curr.push(child);
        dp[child] = 1;
    }

    int ans = 1 + children[0].size();
    int sum = children[0].size(), next_sum = 0;
    while (!curr.empty()) {
        next_sum = 0;
        while (!curr.empty()) {
            auto u = curr.front();
            curr.pop();

            for (int child : children[u]) {
                next.push(child);
                dp[child] = (sum%MOD - dp[u]%MOD + MOD) % MOD;
                next_sum = (next_sum + dp[child]) % MOD;
            }
        }

        ans = (ans + next_sum) % MOD;
        sum = next_sum;
        swap(curr, next);
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}