#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // slope of 1 -> 2: (y2 - y1) / (x2 - x1)
        // slope of 2 -> 3: (y3 - y2) / (x3 - x2)

        ll d = (y2 - y1) * (x3 - x2)  - (y3 - y2) * (x2 - x1);
        if (d == 0) {
            cout << "TOUCH\n";
        } else if (d > 0) {
            cout << "RIGHT\n";
        } else {
            cout << "LEFT\n";
        }
    }
}
