#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int n, m; ll k;
    cin >> n >> m >> k;
    int nmoves = n + m - 2;

    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    vector<tuple<int,int,ll>> l;
    for (int i=0; i<(1<<(nmoves/2)); i++) {
        // bit 1 = move right
        int y = __builtin_popcount(i);
        int x = nmoves/2 - y;
        if (x >= n || y >= m) continue;

        ll curr = a[0][0];
        int xx = 0, yy = 0;
        for (int j=0; j<nmoves/2; j++) {
            if (i & (1 << j)) yy++;
            else xx++;
            curr ^= a[xx][yy];
        }

        l.push_back(make_tuple(xx, yy, curr));
    }
    sort(l.begin(), l.end());

    ll ans = 0;
    for (int i=0; i<(1<<(nmoves - nmoves/2)); i++) {
        int y = __builtin_popcount(i);
        int x = nmoves - nmoves/2 - y;
        if (x >= n || y >= m) continue;

        ll curr = 0;
        int xx = n-1, yy = m-1;
        for (int j=0; j<nmoves-nmoves/2; j++) {
            curr ^= a[xx][yy];
            if (i & (1 << j)) yy--;
            else xx--;
        }

        auto lb = lower_bound(l.begin(), l.end(), make_tuple(xx, yy, curr ^ k));
        auto ub = upper_bound(l.begin(), l.end(), make_tuple(xx, yy, curr ^ k));
        ans += distance(lb, ub);
    }

    cout << ans << '\n';
}