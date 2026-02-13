#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;

    pair<int, int> q[n];
    for (int i=0; i<n; i++) cin >> q[i].f;
    for (int i=0; i<n; i++) cin >> q[i].s;

    int ans = 0;
    int sum = 0;
    set<int> sides;
    for (int i=0; i<k && i<n; i++) {
        sum += q[i].f;
        sides.insert(q[i].s);
        int curr = sum + (k-i-1) * (*sides.rbegin());
        if (curr > ans) ans = curr;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        solve();
    }
}