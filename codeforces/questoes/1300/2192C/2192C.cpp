#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, h, k;
        cin >> n >> h >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        ll sum = 0;
        for (int i=0; i<n; i++) sum += a[i];

        ll ans = 0;
        if (h >= sum) {
            ans += ll(h / sum) * (n + k);
            h %= sum;
        }

        if (h == 0) {
            ans -= k;
            cout << ans << '\n';
            continue;
        }

        sum = 0;
        int start;
        for (int start=0; start<n && sum < h; start++) sum += a[start];


        vector<int> small(n), big(n);
        small.front() = a.front();
        for (int i=1; i<n; i++) small[i] = min(a[i], small[i-1]);
        big.back() = a.back();
        for (int i=n-2; i>=0; i--) big[i] = max(a[i], big[i+1]);

        vector<ll> prefix(n);
        prefix.front() = a.front();
        for (int i=1; i<n; i++) prefix[i] = prefix[i-1] + a[i];

        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;

            if (prefix[mid] - small[mid] + max(small[mid], big[mid+1]) >= h) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << ans + r + 1 << '\n';
    }
}