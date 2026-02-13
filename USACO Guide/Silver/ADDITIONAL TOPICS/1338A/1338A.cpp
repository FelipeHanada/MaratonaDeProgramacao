#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int big = INT32_MIN, ans = 0, a;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a < big)
            ans = max(ans, (int)log2(big - a) + 1);
        big = max(big, a);
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