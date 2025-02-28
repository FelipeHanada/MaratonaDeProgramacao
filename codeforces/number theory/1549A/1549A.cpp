#include <bits/stdc++.h>
using namespace std;

/*
p >= 5 is a prime number
x = p mod a = p mod b, for 2 <= a < b
p = a*k1 + x = b*k2 + x
p - x = a*k1 = b*k2

then a, b are two integers that divides (p-x) > 0

let p >= 5, p is odd
let x = 1, then p - 1 is odd and divisible by 2 and by itself
*/

int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        cout << 2 << " " << n-1 << "\n";
    }
}