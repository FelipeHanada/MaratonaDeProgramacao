#include <bits/stdc++.h>
using namespace std;

#define _f first
#define _s second
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        if (((x+y)%2 && !y) || (!((x+y)%2) && !x) || x > y) {
            cout << "NO\n";
            continue;
        }

        if (x == 0) {
            y--;
            for (int i=0; i<y; i++) {
                cout << "1 " << 2+i << '\n';
            }
            continue;
        }

        if ((x + y) % 2) {
            y--;
        } else {
            x--;
        }

        int i = 1;
        while (x && y) {
            cout << i << ' ' << i+1 << '\n';
            cout << i+1 << ' ' << i+2 << '\n';
            x--;
            y--;
            i+=2;
        }

        while (y) {
            cout << 1 << ' ' << i+1 << '\n';
            i++;
            y--;
        }
    }
}
