#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
let x, y be the resulting times to produce cookies and muffins respec.
it must be true that:
1) 1 <= x <= t_c
2) 1 <= y <= t_m
3) x + y = t_c + t_m - z
    where z is the amount of moonies spent
4) x*a_i + y*b_i <= c_i (for all 1 <= i <= n)

we can take y = t_c + t_m - z - x from eq.3
and input it into the inequality 4, obtaining
    x*a_i + (t_c + t_m - z - x)*b_i <= c_i (for all 1 <= i <= n)
    x*a_i + (t_c + t_m - z)*b_i - x*b_i <= c_i
    x*(a_i - b_i) <= c_i + b_i*(z - t_c - t_m)

inputting it into the inequality 2:
    1 <= t_c + t_m - z - x <= t_m
    z - t_c - t_m + 1 <= - x <= z - t_c - t_m + t_m = z - t_c
    t_c - z <= x <= t_c + t_m - z - 1
    with the first inequalities
        max(1, t_c - z) <= x <= min(t_c, t_c + t_m - z - 1)

    this gives us three situations:

        1) a_i - b_i > 0
            x <= [c_i + b_i*(z - t_c - t_m)] / (a_i - b_i)

        2) a_i - b_i < 0
            x >= [c_i + b_i*(z - t_c - t_m)] / (a_i - b_i)

        3) a_i - b_i = 0
            0 <= c_i + b_i*(z - t_c - t_m)
*/

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; ll tc, tm;
        cin >> n >> tc >> tm;
        vector<ll> a(n), b(n), c(n);
        for (int i=0; i<n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }

        auto check = [&](ll z) -> bool {
            // max(1, t_c - z) <= x <= min(t_c, t_c + t_m - z - 1)
            ll lower = max(1LL, tc - z), upper = min(tc, tc + tm - z - 1);

            for (int i=0; i<n; i++) {
                if (a[i] > b[i]) {
                    // x <= [c_i + b_i*(z - t_c - t_m)] / (a_i - b_i)
                    upper = min(upper, (c[i] + b[i]*(z - tc - tm)) / (a[i] - b[i]));
                } else if (a[i] < b[i]) {
                    // x >= [c_i + b_i*(z - t_c - t_m)] / (a_i - b_i)

                    lower = max(lower, (c[i] + b[i]*(z - tc - tm) + (a[i] - b[i]) + 1) / (a[i] - b[i]));
                } else {
                    if (c[i] + b[i]*(z - tc - tm) < 0) return 0;
                }
            }

            return lower <= upper;
        };

        if (check(0)) {
            cout << "0\n";
        } else {
            ll l = 0, r = tc + tm - 2;
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }

            cout << r << '\n';
        }
    }
}