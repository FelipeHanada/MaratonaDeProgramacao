#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        array<ll,2> u = { y2 - y1, x1 - x2 },
                     v = { x3 - x1, y3 - y1 };
        
        int dot = u[0] * v[0] + u[1] * v[1];
        if (dot == 0) {
            cout << "TOUCH\n";
        } else if (dot > 0) {
            cout << "RIGHT\n";
        } else {
            cout << "LEFT\n";
        }
    }
}