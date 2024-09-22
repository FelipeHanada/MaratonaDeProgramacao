#include <bits/stdc++.h>
using namespace std;


//  __builtin_ctz(x) counts the trailing zeros of x
int bin_gcd(int a, int b) {
    if (a == 0 || b == 0) return a | b;

    unsigned shift = __builtin_ctz(a | b);
    //  shift = smallest power of two that divides both a and b

    a >>= __builtin_ctz(a);  // divides by two until a is odd
    do {
        b >>= __builtin_ctz(b);  // divides by two until b is odd
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    
    return a << shift;
}

int main() {
    cout << bin_gcd(8, 2) << endl;
    cout << bin_gcd(3, 5) << endl;
}