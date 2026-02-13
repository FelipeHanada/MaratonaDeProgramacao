#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    int xa = n/100, xb = (n/10)%10, xc = n%10;
    int ya = m/100, yb = (m/10)%10, yc = m%10;
    ll a = ya, b = yb, c;
    for (int x=10; x<=15000; x++) {
        c = yc - xa*x*x - xb*x - xc;

        ll delta = b*b - 4*a*c;
        if (delta < 0) continue;
        ll sqrtD = sqrt(delta);
        if (sqrtD*sqrtD != delta) continue;

        if ((-b+sqrtD) % (2*a) == 0) {
            ll y = (-b+sqrtD) / (2*a);
            if (y >= 10 && y <= 15000) {
                cout << x << ' ' << y << '\n';
                return;
            }
        }

        if ((-b-sqrtD) % (2*a) == 0) {
            ll y = (-b-sqrtD) / (2*a);
            if (y >= 10 && y <= 15000) {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
    }
}

int main() {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);

    int k;
    cin >> k;

    for (int i=0; i<k; i++) {
        solve();
    }
}
