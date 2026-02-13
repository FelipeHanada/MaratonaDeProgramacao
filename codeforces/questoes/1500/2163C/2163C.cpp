#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i=0; i<n; i++) cin >> a1[i];
    for (int i=0; i<n; i++) cin >> a2[i];

    // we need to compute the maximum minimum value such that is possible to make the path
    // and the minimum maximum value as such

    int l, r;
    vector<int> dp1(n), dp2(n);
    dp1[0] = a1[0];
    dp2[0] = min(dp1[0], a2[0]);
    for (int i=1; i<n; i++) {
        dp1[i] = min(dp1[i-1], a1[i]);
        dp2[i] = min(max(dp2[i-1], dp1[i]), a2[i]);
    }
    l = dp2.back();

    dp2[0] = max(dp1[0], a2[0]);
    for (int i=1; i<n; i++) {
        dp1[i] = max(dp1[i-1], a1[i]);
        dp2[i] = max(min(dp2[i-1], dp1[i]), a2[i]);
    }
    r = dp2.back();

    cout << l * (2*n - r + 1) << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
