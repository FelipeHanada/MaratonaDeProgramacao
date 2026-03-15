#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n), a(n);
        for (int i=0; i<n; i++) cin >> p[i];
        for (int i=0; i<n; i++) cin >> a[i];

        int i=0, j=0;
        while (j < n) {
            while (j<n-1 && a[j] == a[j+1]) j++;
            while (i < n && p[i] != a[j]) i++;
            if (i == n) break;
            i++; j++;
        }

        cout << (j == n ? "YES" : "NO") << '\n';
    }
}
