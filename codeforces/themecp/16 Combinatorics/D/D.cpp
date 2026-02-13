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

    ans := left*(1*(2^n - P)) * rest

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

        vector<int> comb = {1};
        while (comb.size() <= n) {
            vector<int> next = {1};
            for (int i=0; i<comb.size()-1; i++) next.push_back(add(comb[i], comb[i+1]));
            next.push_back(1);
            swap(comb, next);
        }

        int P = 0;
        for (int i=1; i<=n; i+=2) {
            P = add(P, comb[i]);
        }

        int power2n = 1;
        power2n = 1;
        for (int i=1; i<=n; i++) power2n = mult(power2n, 2);

        int power2ns[k+1];
        power2ns[0] = 1;
        for (int i=1; i<=k; i++) power2ns[i] = mult(power2ns[i-1], power2n);
        
        int left = 1, ans = 0;
        for (int i=0; i<k; i++) {
            ans = add(ans, mult(mult(left, sub(power2n, P)), power2ns[k-i-1]));

            left = mult(left, add(add(1, P), add(sub(power2n, 1), sub(power2n, P))));
        }

        ans = add(ans, left);

        cout << ans << '\n';
    }
}