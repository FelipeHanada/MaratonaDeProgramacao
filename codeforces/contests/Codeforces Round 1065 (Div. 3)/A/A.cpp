#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define _1 first
#define _2 second
#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    if (n % 2 || !n) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    for (int i=0; (n - i*2) >= 0; i++) {
        if ((n - i*2) % 4 == 0) ans++;
    }
    cout << ans << '\n';
}


int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
