#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<array<ll,2>> a(m);
    for (int i=0; i<m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());

    auto check = [&](ll d) -> bool {
        int remaining = n;

        ll last = -d;
        for (int i=0; i<m; i++) {
            while (last + d <= a[i][1]) {
                last = max(a[i][0], last + d);
                if (--remaining == 0) return 1;
            }
        }
        return 0;
    };

    ll l = 1, r = ll(1e18);
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
}
