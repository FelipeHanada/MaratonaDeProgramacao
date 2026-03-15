#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;
    vector<array<int,2>> a(n);
    for (int i=0; i<n; i++) cin >> a[i][0] >> a[i][1];

    auto dist = [&](int i, int j) -> ll {
        ll dx = abs(a[i][0] - a[j][0]);
        ll dy = abs(a[i][1] - a[j][1]);
        return dx*dx + dy*dy;
    };

    auto check = [&](ll X) -> bool {
        vector<bool> seen(n, 0);
        queue<int> bfs;
        bfs.push(0); seen[0] = 1;
        int cnt = 0;
        while (!bfs.empty()) {
            auto curr = bfs.front(); bfs.pop();
            cnt++;

            for (int i=0; i<n; i++) if (!seen[i]) {
                if (dist(curr, i) <= X) {
                    seen[i] = 1;
                    bfs.push(i);
                }
            }
        }

        return cnt == n;
    };

    ll l = 0, r = ll(25000)*25000+1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r << '\n';
}
