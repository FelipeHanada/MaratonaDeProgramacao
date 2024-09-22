#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll bin_pow(ll n, int k) {
    ll r = 1;
    while (k > 0) {
        if (k & 1)
            r *= n;

        n *= n;
        k >>= 1;
    }
    return r;
}

int main() {
    int n;
    cin >> n;

    // interval n on the edge: 3 * 4^(n-3)
    ll a = 2 * (3 * bin_pow(4, n - 3));
    // interval n not on the edge: 3^2 * 4^(n-4)
    ll b = (n - 3) * (9 * bin_pow(4, n - 4));
    
    cout << 4 * (a + b) << endl;
}
