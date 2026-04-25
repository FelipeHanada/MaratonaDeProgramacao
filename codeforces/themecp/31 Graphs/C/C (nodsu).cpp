#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    a[0] = 0;
    for (int i=1; i<n; i++) cin >> a[i];


    vector<int> next(2*n, -1);
    vector<vector<int>> prev(2*n);
    for (int i=1; i<n; i++) {
        if (i+a[i] < n) {
            next[i] = n+i+a[i];
            prev[n+i+a[i]].push_back(i);
        }
        if (i-a[i] >= 0) {
            next[n+i] = i-a[i];
            prev[i-a[i]].push_back(n+i);
        }
    }

    vector<ll> dp(2*n, -1);
    queue<int> q;
    for (int i=1; i<2*n; i++) if (next[i] == -1) {
        q.push(i);
        dp[i] = a[i%n];
    }

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (int p : prev[curr]) {
            dp[p] = dp[curr] + a[p % n];
            q.push(p);
        }
    }

    vector<bool> can_make_cycle(2*n, 0);
    can_make_cycle[0] = 1;
    while (!q.empty()) q.pop();
    q.push(0);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        for (int p : prev[curr]) {
            can_make_cycle[p] = 1;
            q.push(p);
        }
    }

    for (int i=1; i<n; i++) {
        if (dp[n+i] == -1 || can_make_cycle[n+i]) {
            cout << "-1\n";
        } else {
            cout << dp[n+i] + i << '\n';
        }
    }
}