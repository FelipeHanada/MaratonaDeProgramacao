#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;


int main() { _
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    vector<array<int,3>> a(n);
    for (int i=0; i<n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);


    auto check = [&](int x, int y) -> bool {
        for (auto [i, j, r] : a) {
            int dx = x - i, dy = y - j;
            if (dx*dx + dy*dy <= r*r) return 1;
        }
        return 0;
    };

    int ans = 0;
    for (int x=x1; x<=x2; x++) {
        ans += 2 - check(x, y1) - check(x, y2);
    }
    for (int y=y1+1; y<y2; y++) {
        ans += 2 - check(x1, y) - check(x2, y);
    }

    cout << ans << '\n';
}
