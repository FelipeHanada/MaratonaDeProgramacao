#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, l;
        cin >> n >> k >> l;

        vector<ll> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<ll> b(n-1);
        for (int i=0; i<n-1; i++) b[i] = a[i+1] - a[i];
        sort(b.rbegin(), b.rend());

        ll ans = 0;
        ll sum = 0;
        ll left = a[0], right = l - a.back();
        int used;
        for (used = 0; used<=k && used<b.size(); used++) {
            ll curr = sum;
            ll remaining = k - used;

            if (remaining) {
                curr += max(left, right);
                remaining--;
            }
            curr += remaining * (left + right);

            ans = max(ans, curr);

            sum += b[used] / 2;
            left += b[used] / 2;
            right += b[used] / 2;
        }

        ll curr = sum;
        ll remaining = k - used;
        if (remaining) {
            curr += max(left, right);
            remaining--;
        }
        curr += remaining * (left + right);
        ans = max(ans, curr);

        cout << ans << '\n';
    }
}
