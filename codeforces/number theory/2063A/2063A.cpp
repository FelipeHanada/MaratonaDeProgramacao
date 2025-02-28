#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, l, r;
    cin >> t;

    /*
    [1, 1] is coprime
    [x, x+1] is always coprime if x != 1
    */

    for (int i=0; i<t; i++) {
        cin >> l >> r;
        if (l + r == 2) {
            cout << 1 << "\n";
        } else {
            cout << r - l << "\n";
        }
    }
}
