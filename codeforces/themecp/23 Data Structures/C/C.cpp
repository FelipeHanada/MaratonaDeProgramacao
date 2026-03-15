#include <bits/stdc++.h>
using namespace std;


using ull = unsigned long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    array<int,3> ans = { 0, -1, -1 };
    map<pair<int, int>, pair<int, int>> m;
    for (int i=0; i<n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        sort(a[i].begin(), a[i].end());

        ans = max(ans, (array<int,3>){ min(min(a[i][0], a[i][1]), a[i][2]), i, -1 });

        if (m.count({a[i][0], a[i][1]})) {
            auto x = m[{a[i][0], a[i][1]}];
            ans = max(ans, (array<int,3>){ min(min(a[i][0], a[i][1]), x.first + a[i][2]), m[{a[i][0], a[i][1]}].second, i});
        }

        if (m.count({a[i][1], a[i][2]})) {
            auto x = m[{a[i][1], a[i][2]}];
            ans = max(ans, (array<int,3>){ min(min(a[i][1], a[i][2]), x.first + a[i][0]), x.second, i });
        }


        if (m.count({a[i][0], a[i][1]})) {
            auto x = m[{a[i][0], a[i][2]}];
            ans = max(ans, (array<int,3>){ min(min(a[i][0], a[i][2]), x.first + a[i][1]), x.second, i});
        }

        m[{a[i][0], a[i][1]}] = max(m[{a[i][0], a[i][1]}], { a[i][2], i });
        m[{a[i][1], a[i][2]}] = max(m[{a[i][1], a[i][2]}], { a[i][0], i });
        m[{a[i][0], a[i][2]}] = max(m[{a[i][0], a[i][2]}], { a[i][1], i });
    }

    if (ans[2] == -1) {
        cout << 1 << '\n';
        cout << ans[1] + 1 << '\n';
    } else {
        cout << 2 << '\n';
        cout << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';
    }
}
