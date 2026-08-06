#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int add(int a, int b, int md) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b, int md) { return ((ll)a * b) % md; }
int binpow(int a, int b, int md) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a, md);
        a = mult(a, a, md);
        b >>= 1;
    }
    return ans;
}

int phi(int k) {
    int ans = k;
    for (int i=2; i*i<=k; i++) {
        if (k % i == 0) {
            while (k % i == 0) k /= i;
            ans -= ans / i;
        }
    }
    if (k > 1) ans -= ans / k;

    return ans;
}


int main() {
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);

    cin >> n >> k;

    int expo;
    if (n < 25) {
        expo = 1 << n;
    } else {
        int phik = phi(k);
        expo = binpow(2, n, phik) + phik;
    }
    
    cout << add(binpow(2, expo, k), 1, k) << '\n';
}


/*
we can use the generalized eulers totient theorem
    a^b mod k = a^(b mod phi(k) + phi(k)) mod k

this happens as long as b >= log2(k)

in this case:
    2^(2^n) mod k
    = 2^(2^n mod phi(k) + phi(k)) mod k         (by eulers totient theorem)

we can compute 2^n mod phi(k) easily using binary exponentiation


2^n >= log2(k)
since k >= log2(k), this is guaranteed to work
    for any n s.t. 2^n >= k
        we can apply this tech. for 2^n >= 1e6 (n > 20)
        and compute 2^n directly for n <= 20, since it fits in a 32-bit integer


*/