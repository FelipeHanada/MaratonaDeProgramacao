#include <bits/stdc++.h>
using namespace std;

#define ll long long


constexpr int MAX_N = 3e5;
vector<int> divs[MAX_N+1];
void precompute() {
    for (int i=2; i<=MAX_N; i++) {
        for (int j=i; j<=MAX_N; j+=i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> dp(n+1, INT32_MAX);
    for (int i=1; i<=n; i++) {
        if (s.count(i)) {
            dp[i] = 1;
            continue;
        }
        for (int d : divs[i]) if (d <= n && dp[i/d] != INT32_MAX && s.count(d)) {
            dp[i] = min(dp[i], dp[i/d] + 1);
        }
    }

    for (int i=1; i<=n; i++) {
        if (dp[i] == INT32_MAX) cout << -1 << ' ';
        else cout << dp[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
