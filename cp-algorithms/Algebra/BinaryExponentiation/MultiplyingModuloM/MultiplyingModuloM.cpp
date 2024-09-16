#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, m;
    cin >> a >> b >> m;

    a %= m;

    int r = 0;
    int c = 1;
    while (b > 0) {
        if (b & 1)
            r = (r + (a * c) % m) % m;
        
        c <<= 1; c %= m;
        b >>= 1;
    }

    cout << r << endl;
}
