#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll x, y, k;
        cin >> x >> y >> k;

        while (k) {
            if (x < y) {
                k = k % (y-1);
                x += k;
                if (x >= y) {
                    x -= y - 1;
                }
                k = 0;
            } else {
                int delta = min(k, y - x % y);
                x += delta;
                k -= delta;
                while (x % y == 0) x /= y;
            }
        }

        cout << x << '\n';
    }
}
