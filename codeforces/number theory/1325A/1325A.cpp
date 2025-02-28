#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, x;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> x;

        // gcd(a,b) + lcm(a,b) = x
        // let a = 1
        // gcd(a,b) = 1 and lcm(a,b) = b
        // 1 + b = x
        // a = 1 and b = x - 1 is a solution

        cout << 1 << " " << x - 1 << "\n";
    }
}