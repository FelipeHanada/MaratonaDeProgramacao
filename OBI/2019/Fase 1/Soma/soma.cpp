#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    if (k == 0) {
        ll ans = 0;
        ll l = 0, r = 0;
        while (l < n) {
            while (l < n && a[l]) l++;
            
            r = max(r, l);
            while (r < n && !a[r]) r++;

            ans += r - l;
            l++;
        }

        cout << ans << '\n';
    } else {
        ll ans = 0;
        ll l = 0, r = 0, rr = 0;
        ll sumr = 0, sumrr = 0;
        while (l < n) {
            while (r < n && sumr + a[r] < k) {
                sumr += a[r++];
            }

            while (rr < n && sumrr + a[rr] <= k) {
                sumrr += a[rr++];
            }

            if (r < n && sumr + a[r] == k) {
                ans += rr - r;
            }

            sumr -= a[l];
            sumrr -= a[l++];
        }

        cout << ans << '\n';
    }
}