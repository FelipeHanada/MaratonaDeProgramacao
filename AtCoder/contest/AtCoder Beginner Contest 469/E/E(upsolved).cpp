#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; string s;
    cin >> n >> k >> s;


    auto check = [&](double p) -> bool {
        vector<double> prefix(n+1);
        prefix[0] = 0;
        for (int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1];
            if (s[i-1] == 'o') prefix[i] += 1 - p;
            else prefix[i] -= p;
        }

        double min_l = 0;
        int l = 0, r = 0, wins = 0;
        while (wins < k) {
            if (s[r] == 'o') wins++;
            r++;
        }
        while (s[l] == 'x') min_l = min(min_l, prefix[++l]);
        while (r <= n) {
            if (prefix[r] - min_l >= 0) return 1;

            if (s[r] == 'o') {
                min_l = min(min_l, prefix[++l]);
                while (s[l] == 'x') min_l = min(min_l, prefix[++l]);
            }
            r++;
        }

        return 0;
    };

    double l = 0, r = 1;
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(9) << l << '\n';
}

/*
let (l, r) be an interval
    with W wins and L losses

    then W*(1-p) - L*p = 0, if win rate in the interval is equal to p
        W*(1-p) - L*p < 0, if win rate in the interval is less than p
        W*(1-p) - L*p > 0, if win rate in the interval is greater than p

proof. lets check each case

I) p = W/(W+L), then
    Wp + Lp = W
    W(p-1) + Lp = 0
    W(1-p) - Lp = 0

II) p > W/(W+L), then (note that W and L are non-negative and W+L>0)
    Wp + Lp > W
    W(p-1) + Lp > 0
    W(1-p) - Lp < 0

III) p < W/(W+L) is the same as (II)


we can binary search for the answer
*/