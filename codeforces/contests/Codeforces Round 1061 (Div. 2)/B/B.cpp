#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<char> op(n);
    bool anyB = false; 
    for (int i=0; i<n; i++) {
        cin >> op[i];
        if (op[i] == 'B') anyB = true;
    }

    int x;
    while (q--) {
        cin >> x;
        if (!anyB) {
            cout << x << '\n';
        } else {
            int ans = 0;
            for (; x; ans++) {
                if (op[ans%n] == 'A') {
                    x--;
                } else {
                    x /= 2;
                }
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
