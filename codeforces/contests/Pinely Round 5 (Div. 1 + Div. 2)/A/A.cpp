#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second


void solve() {
    int r, x, d, n;
    cin >> r >> x >> d >> n;
    int ans = 0;
    char c;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c == '1') {
            ans++;
            r -= d;
        } else {
            if (r < x) {
                ans++;
                r -= d;
            }
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
