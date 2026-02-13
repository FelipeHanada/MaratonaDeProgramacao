#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    vector<array<int,3>> q1, q2, q3, q4;
    vector<array<int,2>> points(n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { x, y };
        if (x >= 0) {
            if (y >= 0) q1.push_back({x, y, i});
            else q2.push_back({x, y, i});
        } else {
            if (y >= 0) q4.push_back({x, y, i});
            else q3.push_back({x, y, i});
        }
    }

    auto sortcos = [&](const array<int,3>& a, const array<int,3>& b) -> bool {
        double ha = sqrt(a[0]*a[0] + a[1]*a[1]), hb = sqrt(b[0]*b[0]+b[1]*b[1]);
        return abs(a[0])/ha < abs(b[0])/hb;
    };
    auto sortsen = [&](const array<int,3>& a, const array<int,3>& b) -> bool {
        double ha = sqrt(a[0]*a[0] + a[1]*a[1]), hb = sqrt(b[0]*b[0]+b[1]*b[1]);
        return abs(a[1])/ha < abs(b[1])/hb;
    };

    sort(q1.begin(), q1.end(), sortcos);
    sort(q2.begin(), q2.end(), sortsen);
    sort(q3.begin(), q3.end(), sortcos);
    sort(q4.begin(), q4.end(), sortsen);

    vector<int> prefix(n);
    int i=0;
    for (auto [x, y] : points) {
        if (x >= 0) {
            if (y >= 0) {
                auto ub = upper_bound(q1.begin(), q1.end(), (array<int,3>){x, y, INT32_MAX}, sortcos);
                prefix[i] = distance(q1.begin(), ub);
            } else {
                auto ub = upper_bound(q2.begin(), q2.end(), (array<int,3>){x, y, INT32_MAX}, sortsen);
                prefix[i] = q1.size() + distance(q2.begin(), ub);
            }
        } else {
            if (y >= 0) {
                auto ub = upper_bound(q4.begin(), q4.end(), (array<int,3>){x, y, INT32_MAX}, sortsen);
                prefix[i] = q1.size() + q2.size() + q3.size() + distance(q4.begin(), ub);
            }
            else {
                auto ub = upper_bound(q3.begin(), q3.end(), (array<int,3>){x, y, INT32_MAX}, sortcos);
                prefix[i] = q1.size() + q2.size() + distance(q3.begin(), ub);
            }
        }
        i++;
    }

    while (q--) {
        int a, b;
        cin >> a >> b; a--; b--;
        int ans = prefix[b];
    }
}
