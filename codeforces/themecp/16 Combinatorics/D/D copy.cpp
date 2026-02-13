#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int mult(int a, int b) {
    return ((ll)a * b) % md;
}

/*
X = a1 & a2 & ... & an
Y = a1 ^ a2 ^ ... ^ an

we want the number of arrays such that
    X >= Y

the ith bit of X is set if
    the ith bit of ai is also set for all i (1)
    and is not set otherwise                (2^n-1)

the ith bit of Y is set if
    the ith bit of ai is also set for an odd amount of i (P)
    and is not set otherwise                             (2^n-P)

P = comb(n, 1) + comb(n, 3) + comb(n, 5) + ... + comb(n, )

for every bit i, we compute the number of arrays where X and Y
    are equal in all bits before i, and differ on the ith bit
        therefore, X ith bit is set and Y is not

    left: count of ways to maintain an equal prefix

    ans := left * ( all set and even amount of bits  ) * rest

    left := left * ( all set and odd amount of bits + not all set and even amount of bits)

    all set and odd amount of bits:         1 if n is odd 0 otherwise
    not all set and even amount of bits:    even amount of bits (- 1 if all set is even bits set)

    rest = 2^(n*k)
*/

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        int P = 1;
        for (int i=1; i<n; i++) P = mult(P, 2);
        int pn = mult(P, 2);

        vector<int> pns(k+1);
        pns[0] = 1;
        for (int i=1; i<=k; i++) pns[i] = mult(pns[i-1], pn);

        int left = 1, ans = 0;
        for (int i=k-1; i>=0; i--) {
            if (n % 2 == 0) ans = add(ans, mult(left, pns[i]));
            
            left = mult(left, add(n % 2, sub(P , 1 - n % 2)));
        }

        ans = add(ans, left);

        cout << ans << '\n';
    }
}