#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
constexpr int md = 998244353;
inline int add(int a, int b) { a += b; if (a >= md) a -= md; return a; }
inline int sub(int a, int b) { a -= b; if (a < 0) a += md; return a; }
inline int mult(int a, int b) { return ((ll)a * b) % md; }


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (r1 < r2) {
            swap(x1, x2);
            swap(y1, y2);
            swap(r1, r2);
        }

        ll dx2 = ll(x1 - x2) * (x1 - x2);
        ll dy2 = ll(y1 - y2) * (y1 - y2);
        ll dr2 = ll(r1 + r2) * (r1 + r2);
        ll d2 = dx2 + dy2;

        if (d2 > dr2 || d2 < (r1 - r2) * (r1 - r2)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}
