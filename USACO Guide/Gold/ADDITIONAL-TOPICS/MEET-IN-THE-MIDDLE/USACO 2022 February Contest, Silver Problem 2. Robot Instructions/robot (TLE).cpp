#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> dxl(n/2), dxr(n-n/2);
    vector<int> dyl(n/2), dyr(n-n/2);
    for (int i=0; i<n/2; i++) cin >> dxl[i] >> dyl[i];
    for (int i=0; i<n-n/2; i++) cin >> dxr[i] >> dyr[i];

    vector<tuple<int,int,int>> l;
    for (int i=0; i<(1<<(n/2)); i++) {
        int xx = 0, yy = 0;
        int mask = i;
        for (int j=0; mask; j++) if (mask & (1<<j)) {
            xx += dxl[j];
            yy += dyl[j];
            mask &= ~(1<<j);
        }

        l.push_back(make_tuple(__builtin_popcount(i), xx, yy));
    }

    sort(l.begin(), l.end());

    vector<ll> ans(n+1, 0);
    for (int i=0; i<(1<<(n-n/2)); i++) {
        int xx = 0, yy = 0;
        int mask = i;
        for (int j=0; mask; j++) if (mask & (1<<j)) {
            xx += dxr[j];
            yy += dyr[j];
            mask &= ~(1<<j);
        }

        for (int k=max(1, __builtin_popcount(i)); k<=n; k++) {
            int rem = k - __builtin_popcount(i);
            auto lb = lower_bound(l.begin(), l.end(), make_tuple(rem, x - xx, y - yy));
            auto ub = upper_bound(l.begin(), l.end(), make_tuple(rem, x - xx, y - yy));
            ans[k] += distance(lb, ub);
        }
    }

    for (int k=1; k<=n; k++) {
        cout << ans[k] << '\n';
    }
}