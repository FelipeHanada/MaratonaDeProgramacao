#include <bits/stdc++.h>
using namespace std;


int gcd_recursive(int a, int b) {
    if (b == 0) return a;
    // a % b = a - (b * k) >= 0
    // k is a positive integer
    return gcd_recursive(b, a % b);
}

int gcd_one_line(int a, int b) {
    return (b == 0) ? a : gcd_one_line(b, a % b);
}

int gcd_iterative(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    cout << gcd_recursive(1, 10) << " " << gcd_one_line(1, 10) << " " << gcd_iterative(1, 10) << endl;
    cout << gcd_recursive(2, 10) << " " << gcd_one_line(2, 10) << " " << gcd_iterative(2, 10) << endl;
    cout << gcd_recursive(5, 10) << " " << gcd_one_line(5, 10) << " " << gcd_iterative(5, 10) << endl;
    cout << gcd_recursive(7, 10) << " " << gcd_one_line(7, 10) << " " << gcd_iterative(7, 10) << endl;
}
