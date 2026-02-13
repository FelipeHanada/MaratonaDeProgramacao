#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define f first
#define s second
constexpr int MAX_N = 100;
int n;
pair<ll, ll> points[MAX_N];


void solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ll d1, d2;
    cout << "? L " << (ll)1e9 << '\n'; cin >> d1;
    cout << "? L " << (ll)1e9 << '\n'; cin >> d1;
    cout << "? D " << (ll)1e9 << '\n'; cin >> d1;
    cout << "? D " << (ll)1e9 << '\n'; cin >> d1;
    // currently, d1 is the distance from (X-2e9,Y-2e9) to bottomleft most point (x, y)
    // this is: d1 = (x - X + 2e9) + (y - Y + 2e9)
    //          X + Y = x + y + 4e9 - d1

    cout << "? R " << (ll)1e9 << '\n'; cin >> d2;
    cout << "? R " << (ll)1e9 << '\n'; cin >> d2;
    cout << "? R " << (ll)1e9 << '\n'; cin >> d2;
    cout << "? R " << (ll)1e9 << '\n'; cin >> d2;
    // currently, d is the distance from (X+2e9,Y-2e9) to bottomright most point (x, y)
    // this is: d2 = (X + 2e9 - x) + (y - Y + 2e9)
    //          X - Y = x - y - 4e9 + d2
    
    pair<int, int> bl = points[0];
    pair<int, int> br = points[0];
    for (int i=1; i<n; i++) {
        if (-points[i].f - points[i].s > -bl.f - bl.s) {
            bl = points[i];
        }
        if (points[i].f - points[i].s > br.f - br.s) {
            br = points[i];
        }
    }

    ll x = (bl.f + bl.s + br.f - br.s - d1 + d2) / 2;
    ll y = bl.f + bl.s + (ll)4e9 - d1 - x;
    cout << "! " << x << ' ' << y << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
