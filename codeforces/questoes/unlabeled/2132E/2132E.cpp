#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n), b(m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        vector<ll> pa(n+1), pb(m+1);
        pa[0] = pb[0] = 0;
        for (int i=1; i<=n; i++) pa[i]= pa[i-1] + a[i-1];
        for (int i=1; i<=m; i++) pb[i]= pb[i-1] + b[i-1];

        vector<array<ll,3>> pz(n+m+1);
        pz[0] = { 0, 0, 0 };
        int cnt_a = 0, cnt_b = 0; ll sum = 0;
        for (int i=1; i<=n+m; i++) {
            if (cnt_a < n && (cnt_b == m || a[cnt_a] > b[cnt_b])) {
                sum += a[cnt_a];
                cnt_a++;
            } else {
                sum += b[cnt_b];
                cnt_b++;
            }

            pz[i] = { cnt_a, cnt_b, sum };
        }

        auto check = [&](int x, int y, int z) -> bool {
            if (pz[z][0] > x) return 0;
            if (pz[z][1] > y) return 0;
            return 1;
        };

        while (q--) {
            int x, y, z; cin >> x >> y >> z;

            if (z == n + m) {
                cout << pa.back() + pb.back() << '\n';
            } else {
                int l = 0, r = z + 1;

                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (check(x, y, mid)) l = mid;
                    else r = mid;
                }

                int x_used = pz[l][0], y_used = pz[l][1];
                int rem = z - (x_used + y_used);
                ll score = pz[l][2];

                if (x_used == x) {
                    score += pb[y_used + rem] - pb[y_used];
                } else {
                    score += pa[x_used + rem] - pa[x_used];
                }

                cout << score << '\n';
            }
        }
    }
}
