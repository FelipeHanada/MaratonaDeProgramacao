#include <bits/stdc++.h>
using namespace std;



int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> L(n), R(n);
    L[0] = 0;
    for (int i=1; i<n; i++) {
        L[i] = max(L[i-1]+1, a[i] - a[i-1]);
    }
    reverse(a.begin(), a.end());
    R[0] = 0;
    for (int i=1; i<n; i++) {
        R[i] = max(R[i-1]+1, a[i-1] - a[i]);
    }
    reverse(a.begin(), a.end());
    reverse(R.begin(), R.end());

    auto check = [&](int r) -> bool {
        // radius = r / 20
        for (int i=0; i<n; i++) {
            if (i && r >= (R[i]+1) * 20) {
                auto lb = lower_bound(a.begin(), a.end(), a[i] - floor(2 * r / 20.0));
                if (r >= (L[distance(a.begin(), lb)]+1) * 20) return 1;
            }

            if (i < n-1 && r >= (L[i]+1) * 20) {
                auto ub = upper_bound(a.begin(), a.end(), a[i] + floor(2 * r / 20.0));
                if (r >= (R[distance(a.begin(), ub) - 1]+1) * 20) return 1;
            }
        }

        return 0;
    };

    int l = 0, r = (a.back() - a.front()) * 20;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r/20 << '.' << (r/2)%10 << '\n';
}
