#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<pair<int, int>> ord(n);
    for (int i=0; i<n; i++) ord[i] = {a[i], i};
    sort(ord.rbegin(), ord.rend());

    vector<int> left(n), right(n);
    stack<pair<int, int>> stk; stk.push({INT32_MAX, -1});
    for (int i=0; i<n; i++) {
        while (stk.top().first <= a[i]) stk.pop();
        left[i] = stk.top().second;
        stk.push({ a[i], i });
    }

    while (!stk.empty()) stk.pop();
    stk.push({INT32_MAX, n});
    for (int i=n-1; i>=0; i--) {
        while (stk.top().first <= a[i]) stk.pop();
        right[i] = stk.top().second;
        stk.push({ a[i], i });
    }

    vector<int> dp(n, 1);
    for (auto [x, i] : ord) {
        int p = 0;
        if (left[i] > -1) p = max(p, dp[left[i]]);
        if (right[i] < n) p = max(p, dp[right[i]]);

        dp[i] += p;
    }

    int ans = 0;
    for (int i=0; i<n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}