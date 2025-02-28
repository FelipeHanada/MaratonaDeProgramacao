#include <bits/stdc++.h>
using namespace std;
#define u64 uint64_t
#define u128 __uint128_t

#define MOD ((u64) 1000000007)
constexpr u64 MAX_N = (u64) 1e8;


u64 mult(u64 a, u64 b) {
    return (u128)(a * b) % MOD;
}

void multmat22(u64 a[2][2], u64 b[2][2]) {
    u64 temp[2][2];

    temp[0][0] = (mult(a[0][0], b[0][0]) + mult(a[0][1], b[1][0])) % MOD;
    temp[0][1] = (mult(a[0][0], b[0][1]) + mult(a[0][1], b[1][1])) % MOD;
    temp[1][0] = (mult(a[1][0], b[0][0]) + mult(a[1][1], b[1][0])) % MOD;
    temp[1][1] = (mult(a[1][0], b[0][1]) + mult(a[1][1], b[1][1])) % MOD;

    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}

u64 fib(u64 n) {
    if (n == 0)
        return 0;
    if (n <= 2)
        return 2;
    
    u64 a[2][2] = { {1, 0}, {0, 1} };
    u64 m[2][2] = { {1, 1}, {1, 0} };

    n--;
    while (n) {
        if (n & 1)
            multmat22(a, m);

        n >>= 1;
        multmat22(m, m);
    }

    return a[0][0];
}


u64 solve(u64 n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 2;


    // By Lames Theorem, gcd performs exactly n - 2 operations
    // when a = fib(n) and b = fib(n - 1)
    return (fib(n + 2) + fib(n + 1)) % MOD;
}

int t; u64 n;
int main() {
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}