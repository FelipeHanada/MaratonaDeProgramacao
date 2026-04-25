#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int n;
    cin >> n; n--;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> next(2*n+1);
    // n first vertices subtract a[i]
    // the n next vertices add a[i]
    // the last vertex is a sink
    next[2*n] = -1;
    for (int i=0; i<n; i++) {
        if (i + a[i] < n) next[i] = n + i + a[i];
        else next[i] = 2*n;

        if (i - a[i] >= 0) next[n+i] = i - a[i];
        else next[n+i] = 2*n;
    }

    vector<vector<int>> inv(2*n+1);
    for (int i=0; i<2*n; i++) {
        inv[next[i]].push_back(i);
    }

    queue<int> q;
    vector<int> dp(2*n+1, -1);
    q.push(2*n);
    dp[2*n] = 0;

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (int i : inv[curr]) {
            dp[i] = dp[curr] + a[i % n];
            q.push(i);
        }
    }

    for (int i=0; i<n; i++) {
        if (dp[n+i] == -1) {
            cout << "-1\n";
        } else {
            cout << dp[n+i] + i + 1 << '\n';
        }
    }
}
