#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 2e5;

int a[MAX_N+1];
deque<int> dq[MAX_N+1];
int dp[MAX_N+1];

void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        dq[i].clear();
        cin >> a[i];
    }
    fill_n(dp, n+1, 0);
    for (int i=1; i<=n; i++) {
        dp[i] = dp[i-1];
        dq[a[i]].push_back(i);
        if (dq[a[i]].size() > a[i]) dq[a[i]].pop_front();
        if (dq[a[i]].size() == a[i]) dp[i] = max(dp[i], dp[dq[a[i]].front()-1] + a[i]);
    }
    cout << dp[n] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
