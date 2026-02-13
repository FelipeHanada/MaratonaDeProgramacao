#include <bits/stdc++.h>
using namespace std;


#define ll long long

// this runs with a greedy strategy

void solve() {
    int n;
    cin >> n;
    deque<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    if (!(n%2)) a.push_back(0);

    ll ans = 0;
    int k;
    for (int i=1; i<n; i+=2) {
        // we have to decrement the next whenever it is possible
        if (a[i-1] + a[i+1] > a[i] && a[i+1] > 0) {
            k = min(a[i+1], a[i-1] + a[i+1] - a[i]);
            ans += k;
            a[i+1] -= k;
        }

        if (a[i-1] + a[i+1] > a[i]) {
            k = a[i-1] - a[i];
            ans += k;
            a[i-1] -= k;
        }
    }

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