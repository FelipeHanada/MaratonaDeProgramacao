#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;

    for (int i=0; i<t; i++) {
        int a, b; cin >> a >> b;

        if (b % a == 0) {
            //  b = a*p
            //  p = smallest prime that divides x
            //  x = b*p  <=>  x = b*b/a
            cout << b / a * b;
        } else {
            //  b = x/p, a = x/q
            //  p = smallest prime that divides n, q = second smallest
            //  gcd(a, b) = x / (p * q)  <=>  x = gcd(a, b) * (p * q)
            //  p = x/b, q = x/a
            //  x = gcd(a, b) * (x/b * x/a)  <=>  a * b / gcd(a, b)
            cout << a / gcd(a, b) * b;
        }
        cout << endl;
    }
}