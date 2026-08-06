#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) { cin >> a[i]; a[i]--; }
    for (int i=0; i<n; i++) { cin >> b[i]; b[i]--; }

    bool ok = 1;
    for (int i=0; i<n; i++) {
        ok = ok && i == b[a[i]];
    }

    cout << (ok ? "Yes" : "No") << '\n';
}