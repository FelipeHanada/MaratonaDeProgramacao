#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct rectangle {
    pair<ll, ll> x_interval = {INT32_MAX, INT32_MIN};
    pair<ll, ll> y_interval = {INT32_MAX, INT32_MIN};
    ll area() {
        ll x_interval_size = max((ll)0, x_interval.second - x_interval.first);
        ll y_interval_size = max((ll)0, y_interval.second - y_interval.first);
        return x_interval_size * y_interval_size;
    }
    void add_point(pair<ll, ll> p) {
        x_interval = {
            min(x_interval.first, p.first),
            max(x_interval.second, p.first)
        };
        y_interval = {
            min(y_interval.first, p.second),
            max(y_interval.second, p.second)
        };
    }
};


int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<ll, ll>> v;
    rectangle single_enclosure;
    for (ll i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
        single_enclosure.add_point({x, y});
    }

    sort(v.begin(), v.end());
    rectangle left, right;
    left.add_point(v[0]);
    right.add_point(v[n-1]);
    ll h_rectangle_areas[n-1] = {};
    for (ll i=0; i<n-1; i++) {
        left.add_point(v[i]);
        right.add_point(v[n-1-i]);

        h_rectangle_areas[i] += left.area();
        h_rectangle_areas[n-2-i] += right.area();
    }

    auto cmp = [&](const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
        return p1.second < p2.second;
    };
    sort(v.begin(), v.end(), cmp);
    rectangle top, bottom;
    top.add_point(v[0]);
    bottom.add_point(v[n-1]);
    ll v_rectangle_areas[n-1] = {};
    for (ll i=0; i<n-1; i++) {
        top.add_point(v[i]);
        bottom.add_point(v[n-1-i]);

        v_rectangle_areas[i] += top.area();
        v_rectangle_areas[n-2-i] += bottom.area();
    }

    ll min_area = single_enclosure.area();
    for (auto area : h_rectangle_areas) {
        min_area = min(min_area, area);
    }
    for (auto area : v_rectangle_areas) {
        min_area = min(min_area, area);
    }

    cout << single_enclosure.area() - min_area << endl;
}
