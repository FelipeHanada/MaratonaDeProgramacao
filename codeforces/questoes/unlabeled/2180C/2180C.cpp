#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        if (k % 2) {
            for (int i=0; i<k; i++) cout << n << ' ';
            cout << '\n';
        } else {
            int a = 0, b = n;
            int x = __builtin_popcount(n);
            for (int i=0; i<31 && x > 1; i++) {
                if (n & (1<<i)) {
                    b &= ~(1<<i);
                    a |= (1<<i);
                    x--;
                } else {
                    a |= (1<<i);
                    b |= (1<<i);
                }
            }

            cout << a << ' ' << b << ' ';
            for (int i=2; i<k; i++) cout << n << ' ';
            cout << '\n';
        }
    }
}
