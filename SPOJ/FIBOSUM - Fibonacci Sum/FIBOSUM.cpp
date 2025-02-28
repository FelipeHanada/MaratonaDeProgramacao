#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll) 1000000007

ll mult(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

void mult_matrix22(ll a[2][2], ll b[2][2]) {
    ll temp[2][2] = {
        {
            (mult(a[0][0], b[0][0]) + mult(a[0][1], b[1][0])) % MOD,
            (mult(a[0][0], b[0][1]) + mult(a[0][1], b[1][1])) % MOD
        },
        {
            (mult(a[1][0], b[0][0]) + mult(a[1][1], b[1][0])) % MOD,
            (mult(a[1][0], b[0][1]) + mult(a[1][1], b[1][1])) % MOD
        }
    };

    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}


ll fib(ll n) {
    if (n <= 0) return 0;
    n--;

    ll a[2][2] = { {1, 0}, {0, 1} };
    ll m[2][2] = { {1, 1}, {1, 0} };

    while (n) {
        if (n & 1)
            mult_matrix22(a, m);

        n >>= 1;
        mult_matrix22(m, m);
    }

    return a[0][0];
}

ll fib_sum(ll n) {
    // return sum fib(0) + fib(1) + ... + fib(n)
    return (fib(n + 2) + (MOD - 1)) % MOD;
}

ll solve(ll n, ll m) {
    return (fib_sum(m) + (MOD - fib_sum(n - 1))) % MOD;
}

int main() {
    int t;
    cin >> t;
    
    ll n, m;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
}
