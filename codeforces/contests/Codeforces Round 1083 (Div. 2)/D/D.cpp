#include <bits/stdc++.h>
using namespace std;



using ll = long long;
#define _1 first
#define _2 second


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> p(n+1);
    for (int i=0; i<n; i++) p[a[i]] = i;

    vector<int> l(n, -1), r(n, -1);
    stack<pair<int, int>> stk;
    for (int i=0; i<n; i++) {
        int last = -1;
        while (!stk.empty() && a[i] > stk.top()._1) {
            last = stk.top()._2;
            stk.pop();
        }
        if (last != -1) l[i] = last;
        if (!stk.empty()) r[stk.top()._2] = i;
        stk.push({ a[i], i });
    }

    int ans = 0;
    vector<int> dp(n, 1);
    for (int i=n; i>0; i--) {
        if (l[p[i]] != -1) dp[l[p[i]]] += dp[p[i]];
        if (r[p[i]] != -1) dp[r[p[i]]] += dp[p[i]];
        if (l[p[i]] == -1 && r[p[i]] == -1) {
            ans = max(ans, dp[p[i]]);
        }
    }

    cout << n - ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) solve();
}
