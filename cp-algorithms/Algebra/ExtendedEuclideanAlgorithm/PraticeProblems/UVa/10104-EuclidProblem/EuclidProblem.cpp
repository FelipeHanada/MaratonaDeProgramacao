#include <bits/stdc++.h>
using namespace std;


int extended_gcd(int a, int b, int &x, int &y) {
    x = 1; y = 0;
    int x1 = 0, y1 = 1;
    while (b != 0) {
        int q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}


int main() {
    int a, b, x, y;
    while (cin >> a >> b) {
        int g = extended_gcd(a, b, x, y);
        cout << x << " " << y << " " << g << endl;
    }
}
