#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        ll ans = 0;
        int small = INT32_MAX, big = INT32_MIN;
        for (int i=0; i<n; i++) {
            small = min(small, a[i]);
            big = max(big, a[i]);
            
            if (i < n - 1) ans += abs(a[i+1] - a[i]);
        }

        int psmall, pbig;
        if (small == 1) psmall = 0;
        else {
            psmall = min(a.front() - 1, a.back() - 1);
            for (int i=0; i<n-1; i++) {
                psmall = min(psmall, 2 * (min(a[i], a[i+1]) - 1));
            }
        }
        if (big >= k) pbig = 0;
        else {
            pbig = min(k - a.front(), k - a.back());

            for (int i=0; i<n-1; i++) {
                pbig = min(pbig, 2 * (k - max(a[i], a[i+1])));
            }
        }

        cout << ans + psmall + pbig << '\n';
    }
}
