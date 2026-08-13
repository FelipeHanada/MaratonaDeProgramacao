#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        for (int i=0; i<n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
        }

        ll ans = 0;
        int big = INT32_MIN;
        for (int i=0; i<n; i++) {
            big = max(big, a[i]);
            ans += b[i];
        }

        cout << ans + big << '\n';
    }
}
