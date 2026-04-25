#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int tx, ty;
        cin >> tx >> ty;
        int x = 0, y = 0;

        if (y > ty) {
            x += 4 * (y - ty);
        } else if (y < ty) {
            x += 2 * (ty - y);
        }

        int dx = tx - x;
        if (dx < 0 || (dx % 3)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}