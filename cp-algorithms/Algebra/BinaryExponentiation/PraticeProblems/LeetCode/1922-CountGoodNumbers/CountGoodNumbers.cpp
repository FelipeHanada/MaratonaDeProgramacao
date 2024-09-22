// https://leetcode.com/problems/count-good-numbers/description/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;

ll bin_pow(ll n, ll k) {
    n %= MOD;
    ll r = 1;
    while (k > 0) {
        if (k & 1)
            r = (r * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return r;
}


int main() {
    ll n;
    cin >> n;

    cout << (bin_pow(5, (n-n/2)) * bin_pow(4, n/2)) % MOD;
}
