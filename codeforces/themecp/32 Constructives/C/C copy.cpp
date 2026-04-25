#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        int small = a[n-1], big = a[n-1];
        int ans = 0;
        for (int i=0; i<n-1; i++) {
            ans += abs(a[i] - a[i+1]);
            small = min(small, a[i]);
            big = max(big, a[i]);
        }

        for (int i=x; i>=1; i++) if (i < small || i > big) {
            ans += i;
            break;
        }

        cout << ans << '\n';
    }
}
