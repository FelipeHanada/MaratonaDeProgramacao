#include <bits/stdc++.h>
using namespace std;


#define ll long long

bool verify(const tuple<int, int, int>& cow, const tuple<int, int, int>& grazing) {
    ll dt = get<0>(cow) - get<0>(grazing);
    ll dx = get<1>(cow) - get<1>(grazing);
    ll dy = get<2>(cow) - get<2>(grazing);
    return dt*dt >= dx*dx + dy*dy;
}

int main() {
    int g, n;
    cin >> g >> n;

    int x, y, t;
    vector<tuple<int, int, int>> grazings(g);
    for (int i=0; i<g; i++) {
        cin >> x >> y >> t;
        grazings[i] = make_tuple(t, x, y);
    }
    sort(grazings.begin(), grazings.end());

    int ans = 0;
    tuple<int, int, int> cow;
    for (int i=0; i<n; i++) {
        cin >> x >> y >> t;
        cow = make_tuple(t, x, y);

        auto ub = upper_bound(grazings.begin(), grazings.end(), cow);

        if ((ub != grazings.end() && !verify(cow, *ub))
            || (ub != grazings.begin() && !verify(cow, *(ub-1)))) ans++;
    }

    cout << ans << '\n';
}
