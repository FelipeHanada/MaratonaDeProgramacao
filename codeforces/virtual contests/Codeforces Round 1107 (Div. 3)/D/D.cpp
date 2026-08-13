#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        bool ok = 1;
        for (int i=0; ok && i<n-1; i++) {
            if (a[i] > b[i]) ok = 0;
            a[i+1] -= b[i] - a[i];
        }

        if (a.back() > b.back()) ok = 0;

        cout << (ok ? "YES" : "NO") << '\n';
    }
}

/*
9
9 8 7 6 5 4 3 2 1
9 9 8 2 4 4 3 5 3
*/
