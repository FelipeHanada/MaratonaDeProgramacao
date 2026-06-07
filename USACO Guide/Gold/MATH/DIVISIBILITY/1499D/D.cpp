#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = int(1e7);

/*
c * lcm(a, b) - d * gcd(a, b) = x

let a = Ag and b = Bg for g = gcd(a, b), then A and B are coprime
    we can use this to rewrite this equation

c * a * b / gcd(a, b) - d * gcd(a, b) = x
c * Ag * Bg / g - d * g = x
c * ABg - d * g = x
c * AB - d = x/g   -> g is a divisor of x
c * AB = x/g + d
AB = (x/g + d) / c   -> c must be a divisor of x/g + d

since A and B are coprime,
    for power of prime p^j in (x/g + d) / c factorization
        p^j is in A factorization or in B factorization.
therefore, there is 2^(number of primes that divide (x/g + d) / c) pairs (A, B)
    for that divisor g of x
*/

int main() {
    vector<int> sieve(2*N+1 , 0);
    for (int i=2; i<=2*N; i++) if (!sieve[i]) {
        for (int j=i; j<=2*N; j+=i) sieve[j]++;
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int c, d, x;
        cin >> c >> d >> x;

        ll ans = 0;

        auto solve = [&](int g) { // assume that g is a divisor of x
            if ((x/g + d) % c) return;
            int y = (x/g+d)/c;
            ans += (1LL << sieve[y]);
        };

        int g;
        for (g = 1; g*g < x; g++) if (!(x % g)) {
            solve(g);
            solve(x / g);
        }
        if (g*g == x) solve(g);

        cout << ans << '\n';
    }
}
