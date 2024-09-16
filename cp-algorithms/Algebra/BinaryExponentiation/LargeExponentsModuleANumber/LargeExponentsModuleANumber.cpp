#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll binpow(ll a, ll b, ll m) {
    a %= m;

    ll r = 1;
    while (b > 0) {
        if (b & 1) r = (r * a) % m;

        a = (a * a) % m;
        b >>= 1;
    }

    return r;
}


int main() {
    cout << binpow(2, 2, 1e9 + 7) << endl;
    cout << binpow(2, 10, 1e9 + 7) << endl;
    cout << binpow(2, 10000, 1e9 + 7) << endl;
}
