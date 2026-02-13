#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    deque<int> prefix(n+1, 0);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        prefix[x]++;
    }
    for (int i=1; i<=n; i++) {
        prefix[i] += prefix[i-1];
    }

    for (int i=n; i>1; i--) {
        int cost = n;
        if (4*i <= n)
        cost -= prefix[n] - prefix[4*i-1];
        cost -= prefix[i] - prefix[i-1];
        if (2*i <= n) cost -= prefix[2*i] - prefix[2*i-1];
        if (3*i <= n) cost -= prefix[3*i] - prefix[3*i-1];
        if (cost <= k) {
            cout << i << '\n';
            return;
        }
    }

    cout << 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}