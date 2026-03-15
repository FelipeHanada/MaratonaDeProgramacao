#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, l, x, y;
    cin >> n >> m >> l >> x >> y;
    vector<array<int,2>> a(n); 
    for (int i=0; i<n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    vector<int> b(m);
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }

    vector<double> cost(n); // time if you take i'th bus
    for (int i=0; i<n; i++) {
        cost[i] = (a[i][1] - a[i][0]) / double(x) + (l - a[i][1]) / double(y);
    }

    vector<array<int,3>> ends;
    for (int i=0; i<n; i++) {
        ends.push_back({ a[i][0], 0, i });
        ends.push_back({ a[i][1], 1, i });
    }
    for (int i=0; i<m; i++) {
        ends.push_back({ b[i], 2, i });
    }
    sort(ends.begin(), ends.end());

    multiset<double> ms;
    vector<double> ans(m);
    while (!ends.empty()) {
        auto [t, type, i] = ends.back();
        ends.pop_back();

        if (type == 0) {
            ms.extract(cost[i]);
        } else if (type == 1) {
            ms.insert(cost[i]);
        } else {
            ans[i] = (l - b[i])/double(y);
            if (!ms.empty()) ans[i] = min(ans[i], *(ms.begin()));
        }
    }

    for (int i=0; i<m; i++) {
        cout << setprecision(9) << ans[i] << '\n';
    }
}
