#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, x;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> x;

        // A = gcd(x, y) + y
        // let y = x-1, then A = x
        // if y < x-1, and y does not divides x, then A < x
        // if y < x-1, and y | x, then gcd(x, y) = gcd(x/y, y) <= max(x/y, y)
        //    then A <= max(x/y + y, 2*y)
        //    then for all x >= 2, A <= x (A = x when x is even and y = x/2)
        // therefore y = x-1 is maximal

        cout << x - 1 << "\n";
    }

}