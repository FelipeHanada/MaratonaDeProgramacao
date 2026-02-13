#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, x;
    cin >> n;
    x = 0;

    for (int i=1; !x && i<=n/2; i++) {
        for (int j=1; !x && j<=n; j++) {
            int guess = (j + i) % n;
            if (guess == 0) guess = n;
            cout << j << ' ' << guess << '\n';
            fflush(stdout);
            cin >> x;
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