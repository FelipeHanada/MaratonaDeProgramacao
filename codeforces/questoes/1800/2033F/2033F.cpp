#include <bits/stdc++.h>
using namespace std;


/*
Let z(k) = F(i) be the first Fibonacci number divisible by k
we can show that F(j) is divisible by k iff. j = i*n

proof.
for Fibonacci numbers we know that gcd(F(i), F(j)) = F(gcd(i, j))

I) if j = i*n
    gcd(F(i), F(j)) = F(i)
    since F(i) is divisible by k, so is F(j)

II) if j != i*n
    suppose by contradiction that F(j) is divisible by k
    then k divides gcd(F(i), F(j)) = F(gcd(i, j))
    by gcd property gcd(i, j) <= i,
    since j != i*n => gcd(i, j) < i
    then F(gcd(i, j)) is a Fibonacci number divisible by k that
        appears before i (contradiction)
    therefore F(j) is not divisible by k
end

Then,
    we can compute the first Fibonacci number F(i) that is divisible by k
        this can be done in O(k) (it can be proven that it will occur in i <= 6k)
    then the n'th Fibonacci number divisible by k is F(i*n)
*/

#define ll long long

constexpr int MOD = 1e9+7;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll i=1;
    ll fibi = 0, fibj = 1;
    while (fibj % k != 0) {
        tie(fibi, fibj) = make_tuple(fibj, (fibi + fibj) % k);
        i++;
    }

    cout << ((i%MOD)*(n%MOD)) % MOD << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}