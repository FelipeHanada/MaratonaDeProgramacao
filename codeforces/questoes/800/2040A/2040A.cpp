#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        int ans = -1;
        // |a[i] - x| = k
        // se x1 <= a[i] => a[i] - x = k => x = a[i] - k
        // se x2 > a[i] => -a[i] + x = k => x = a[i] + k

        for (int i=0; i<n; i++) {
            bool ok = true;
            for (int j=0; j<n; j++) if (j != i) {
                if (!(abs(a[i] - a[j]) % k)) {
                    ok = false;
                }
            }
            if (ok) ans = i;
        }

        if (ans >= 0) {
            cout << "YES\n";
            cout << ans + 1 << '\n';
        } else {
            cout << "NO\n";
        }
    }
}
