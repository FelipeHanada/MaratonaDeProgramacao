#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second


void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    ll a, b, c, d;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c >> d;

        if (b > d) { // there are more 1's than necessary
            ans += a + b - d; // all the zeros will be moved sometime
        } else if (a > c) {
            ans += a - c;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    for (int i=0; i<t; i++) {
        solve();
    }
}