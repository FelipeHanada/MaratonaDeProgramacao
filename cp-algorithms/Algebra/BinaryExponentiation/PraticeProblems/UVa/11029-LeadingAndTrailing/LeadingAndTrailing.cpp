// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1970
#include <bits/stdc++.h>
using namespace std;


int bin_pow(int x, int y, int m) {
    x %= m;
    int r = 1;
    while (y > 0) {
        if (y & 1)
            r = (r * x) % m;

        y >>= 1;
        x = (x * x) % m;
    }
    return r;
}

int leading_digits(int n, int k) {
    /*
    n^k = (LLL...TTT)b10
    n^k = (L,LL...TTT)b10 * 10^floor(log10(n^k))

    n^k = (L,LL...TTT)b10 * 10^floor(k * log10(n))
    (L,LL...TTT)b10 = (n^k) / (10^floor(k * log10(n)))
    log10((L,LL...TTT)b10) = log10((n^k) / (10^floor(k * log10(n))))
    log10((L,LL...TTT)b10) = log10(n^k) - log10(10^floor(k * log10(n)))
    log10((L,LL...TTT)b10) = k * log10(n) - floor(k * log10(n))
    (L,LL...TTT)b10 = 10^(k * log10(n) - floor(k * log10(n)))

    (LLL,...TTT)b10 = (L,LL...TTT)b10 * 10^2
    */

    double exp = k * log10(n);
    double log10frac = exp - floor(exp);
    double frac = pow(10, log10frac);
    int leading = frac * 100;
    return leading;
}


int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n, k;
        cin >> n >> k;

        cout << setfill('0') << setw(3) << leading_digits(n, k);
        cout << "..." << setfill('0') << setw(3) << bin_pow(n, k, 1000) << endl;
    }
}
