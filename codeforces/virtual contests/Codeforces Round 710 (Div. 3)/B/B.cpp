#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<int> star;
    for (int i=0; i<n; i++) {
        if (s[i] == '*') star.push_back(i);
    }

    if (star.empty()) {
        cout << 0 << '\n';
    }
    int ans = 1;
    int last_placed = star.front();
    star.pop_front();
    while (star.size() > 1) {
        while (star.size() > 1 && last_placed + k >= star[1]) {
            star.pop_front();
        }

        last_placed = star.front();
        ans++;
        star.pop_front();
    }
    if (star.size()) ans++;
    
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}