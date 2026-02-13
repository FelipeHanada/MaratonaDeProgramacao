#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    map<char, int> chars;
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        chars.insert({c, 0});
        chars[c]++;
    }

    int doubles = 0, singles = 0;
    for (auto [c, x] : chars) {
        doubles += x / 2;
        singles += x % 2;
    }

    int ans = doubles / k * 2 + ((singles + doubles % k >= k - doubles % k) ? 1 : 0);
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        solve();
    }
}