#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int c = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x) {
            // time necessary to take x hikes
            // c >= k + (x-1)*(k+1)
            // x <= ((c-k)/(k+1))+1
            if (c >= k) ans += ((c-k)/(k+1))+1;
            c = 0;
        } else {
            c++;
        }
    }
    if (c >= k) ans += ((c-k)/(k+1))+1;
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}