#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    cin >> a[0];
    int big = a[0];
    int delta;
    for (int i=1; i<n; i++) {
        cin >> a[i];

        if (i % 2) {
            a[i] = big = max(big, a[i]);
            if (a[i-1] >= max(big, a[i])) {
                delta = a[i-1] - a[i] + 1;
                ans += max(0, delta);
                a[i-1] -= a[i-1] - a[i] + 1;
            }
        } else {
            delta = max(0, a[i] - a[i-1] + 1);
            big = max(big, a[i]);
            ans += delta;
            a[i] -= delta;
        }
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
