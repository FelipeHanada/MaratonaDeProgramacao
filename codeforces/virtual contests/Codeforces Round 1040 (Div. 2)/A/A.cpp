#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

void precompute() {
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            ans++;
        } else {
            ans += x;
        }
    }

    cout << ans << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}