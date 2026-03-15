#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int i=0; i<n; i++) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());

        bool ok = 1;
        vector<bool> seen(n, 0);
        for (int i=0; ok && i<n; i++) {
            if (seen[i]) continue;
            vector<int> c;
            
            int j = i;
            while (j < n) {
                seen[j] = 1;
                c.push_back(a[j]);
                j = (j + 1) * 2 - 1;
            }
            sort(c.begin(), c.end());

            j = i;
            for (int x : c) {
                if (x != b[j]) ok = 0;
                j = (j + 1) * 2 - 1;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}