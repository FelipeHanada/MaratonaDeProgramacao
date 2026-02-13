#include <bits/stdc++.h>
using namespace std;


using ll = long long;

bool sortf(const array<int,3> &a, const array<int,3> &b) {
    int q1, q2;
    if (a[0] >= 0) {
        if (a[1] >= 0) q1 = 1;
        else q1 = 2;
    } else {
        if (a[1] >= 0) q1 = 4;
        else q1 = 3;
    }
    if (b[0] >= 0) {
        if (b[1] >= 0) q2 = 1;
        else q2 = 2;
    } else {
        if (b[1] >= 0) q2 = 4;
        else q2 = 3;
    }
    if (q1 != q2) return q1 < q2;

    ll ha = a[0]*a[0] + a[1]*a[1], hb = b[0]*b[0]+b[1]*b[1];
    ll w1, w2;
    if (q1 == 1 || q1 == 3) {
        w1 = (ll)a[0]*a[0]*hb;
        w2 = (ll)b[0]*b[0]*ha;
    } else {
        w1 = (ll)a[1]*a[1]*hb;
        w2 = (ll)b[1]*b[1]*ha;
    }

    if (w1 == w2) return a[2] < b[2];
    return w1 < w2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<array<int,2>> points(n);
    vector<array<int,3>> sorted(n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        if (!x && y) y /= abs(y);
        else if (x && !y) x /= abs(x);
        else if (x && y) {
            int g = abs(__gcd(x, y));
            x /= g; y /= g;
        }

        points[i] = { x, y };
        sorted[i] = { x, y, i };
    }

    sort(sorted.begin(), sorted.end(), sortf);

    vector<int> prefix(n);
    int i=0;
    for (auto [x, y] : points) {
        auto ub = upper_bound(sorted.begin(), sorted.end(), (array<int,3>){ x, y, INT32_MAX }, sortf);
        prefix[i++] = distance(sorted.begin(), ub);
    }

    while (q--) {
        int a, b;
        cin >> a >> b; a--; b--;

        if (prefix[b] >= prefix[a]) {
            int ans = prefix[b];
            auto lb = lower_bound(sorted.begin(), sorted.end(), (array<int,3>){ points[a][0], points[a][1], INT32_MIN }, sortf);
            if (lb != sorted.begin()) ans -= prefix[(*(lb-1))[2]];
            cout << ans << '\n';
        } else {
            int ans = prefix[b];
            auto lb = lower_bound(sorted.begin(), sorted.end(), (array<int,3>){ points[a][0], points[a][1], INT32_MIN }, sortf);
            ans += n - prefix[(*(lb-1))[2]];
            cout << ans << '\n';
        }
    }
}
