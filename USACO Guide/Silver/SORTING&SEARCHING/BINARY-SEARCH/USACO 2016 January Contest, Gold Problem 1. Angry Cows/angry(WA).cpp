#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;
    vector<float> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<float> left(n), right(n);
    left[0] = 0;
    for (int i=1; i<n; i++) {
        left[i] = max(left[i-1]+1, a[i] - a[i-1]);
    }
    left[0] = INT32_MIN;
    reverse(a.begin(), a.end());
    right[0] = 0;
    for (int i=1; i<n; i++) {
        right[i] = max(right[i-1]+1, a[i-1] - a[i]);
    }
    right[0] = INT32_MIN;
    reverse(right.begin(), right.end());
    reverse(a.begin(), a.end());


    auto check = [&](float rad) -> bool {
        for (int i=0; i<n; i++) {
            auto ub = upper_bound(a.begin(), a.end(), a[i] + 2*rad);

            if (rad-1 >= left[i] && rad-1 >= right[distance(a.begin(), ub)-1]) return 1;
            if (i) {
                auto lb = lower_bound(a.begin(), a.end(), a[i] - (2*rad));
                if (rad-1 >= right[i] && rad-1 >= left[distance(a.begin(), lb)]) return 1;
            }
        }

        return 0;
    };


    int ans = INT32_MAX;
    int l = 0, r = 4 * (a.back() - a.front());
    // 0.25
    while (r - l > 1) {
        int mid = (l + r) / 2;

        if (check(mid * 0.25)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (r % 2) cout << fixed << setprecision(1) << (r - 1) * 0.25 << '\n';
    else cout << fixed << setprecision(1) << r * 0.25 << '\n';
}