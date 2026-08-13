#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);



int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n, c; cin >> n >> c;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        int suma = 0, sumb = 0;
        for (int i=0; i<n; i++) suma += a[i];
        for (int i=0; i<n; i++) sumb += b[i];

        bool bad = 0;
        for (int i=0; i<n; i++) {
            if (b[i] > a[i]) bad = 1;
        }
        
        bool badbad = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i=0; i<n; i++) {
            if (b[i] > a[i]) badbad = 1;
        }

        if (badbad) {
            cout << "-1\n";
            continue;
        }

        int ans = bad * c;
        for (int i=0; i<n; i++) ans += a[i] - b[i];
        cout << ans << '\n';
    }
}

/*

*/