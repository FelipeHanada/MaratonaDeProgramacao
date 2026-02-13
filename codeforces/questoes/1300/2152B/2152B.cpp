#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    // doran can always catch krug
    
    ll dx, dy;
    dx = (x1 > x2) ? (n - x2) : ((x1 < x2) ? x2 : 0);
    dy = (y1 > y2) ? (n - y2) : ((y1 < y2) ? y2 : 0);
    cout << max(dx, dy) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}