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

    vector<vector<pair<int,int>>> l(n/2+1);
    for (int i=0; i<(1<<(n/2)); i++) {
        int xx = 0, yy = 0;
        for (int j=0; j<n/2; j++) if (i & (1<<j)) {
            xx += dxl[j];
            yy += dyl[j];
        }

        l[__builtin_popcount(i)].push_back(make_pair(xx, yy));
    }

    for (int i=0; i<=n/2; i++) {
        sort(l[i].begin(), l[i].end());
    }

    vector<ll> ans(n+1, 0);
    for (int i=0; i<(1<<(n-n/2)); i++) {
        int xx = 0, yy = 0;
        for (int j=0; j < n-n/2; j++) if (i & (1<<j)) {
            xx += dxr[j];
            yy += dyr[j];
        }

        for (int rem = 0; __builtin_popcount(i) + rem <= n && rem <= n/2; rem++) {
            auto lb = lower_bound(l[rem].begin(), l[rem].end(), make_pair(x - xx, y - yy));
            auto ub = upper_bound(l[rem].begin(), l[rem].end(), make_pair(x - xx, y - yy));
            ans[__builtin_popcount(i) + rem] += distance(lb, ub);
        }
    }

    for (int k=1; k<=n; k++) {
        cout << ans[k] << '\n';
    }
}
