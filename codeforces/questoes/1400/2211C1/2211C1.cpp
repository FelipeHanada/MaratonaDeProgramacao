#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        bool ok = 1;
        for (int i=0; i<n-k; i++) {
            if (b[i] != -1 && a[i] != b[i]) ok = 0;
            if (b[n-i-1] != -1 && a[n-i-1] != b[n-i-1]) ok = 0;
            b[i] = a[i];
            b[n-i-1] = a[n-i-1];
        }

        vector<bool> seen(n+1, 0);
        for (int i=0; i<n; i++) if (b[i] != -1) {
            if (seen[b[i]]) ok = 0;
            seen[b[i]] = 1;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}

/*

if a number occurs atleast two times in b
    its impossible

considering that this not occur:

if k = n, then its always possible
if k = n - 1, then a[1] = b[1] and a[n] = b[n]
if k = n - 2, then for i \in {1, 2, n-1, n} a[i] = b[i]
...
*/