#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int md = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}

/*
let prefix[i] = xor[1..i]

prefix[i] = i       , if i mod 4 = 0
            1       , if i mod 4 = 1
            i+1     , if i mod 4 = 2
            0       , if i mod 4 = 3


lets prove by induction that this property holds for all i
for i=0, the proposition works (prefix[0] = 0)

for some i, assume that the proposition holds for i-1:
I) i mod 4 = 0 and assume that prefix[i-1] = 0
    then prefix[i] = xor[1..i] = prefix[i-1] ^ i = i
II) i mod 4 = 1 and assume that prefix[i-1] = i-1
    then prefix[i] = xor[1..i] = prefix[i-1] ^ i = (i-1) ^ i
    since i-1 is even, (i-1) and i differ only in the less significant bit
    therefore, prefix[i] = 1
III) i mod 4 = 2 and assume that prefix[i-1] = 1
    then prefix[i] = xor[1..i] = prefix[i-1] ^ i = 1 ^ i
    since i is even, prefix[i] = i + 1
IV) i mod 4 = 3 and assume that prefix[i-1] = i
    then prefix[i] = xor[1..i] = prefix[i-1] ^ i = i ^ i = 0


for any pair (l, r) to satisfy the problem, we need that
    prefix[l-1] = prefix[r]
this is only possible when
    i) prefix[l-1] = prefix[r] = 0
    ii) prefix[l-1] = prefix[r] = 1
*/

inline int solve1(ll k) { return ((k + 3) / 4) % md; } // counts prefix[i] = 1 st. i <= k
inline int solve2(ll k) { return (1 + (k + 1) / 4) % md; } // counts prefix[i] = 0 st. i <= k

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, x;
        cin >> n >> x;

        ll ans1 = mult(solve1(x-1), add(solve1(n), -solve1(x-1)));
        ll ans2 = mult(solve2(x-1), add(solve2(n), -solve2(x-1)));
        cout << add(ans1, ans2) << '\n';
    }
}