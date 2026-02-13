#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    int big = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        big = max(big, ++m[x]);
    }

    if (big > n - big) {
        cout << big - n + big << '\n';
    } else {
        cout << n % 2 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
