#include <bits/stdc++.h>
using namespace std;


int bin_gcd(int a, int b) {
    if (a == 0 || b == 0) return a | b;

    unsigned int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    
    return a << shift;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << bin_gcd(a, b) << endl;
}
