#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9) + 7;
constexpr int inv2 = (md + 1) / 2;
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


int main() {
    ll n;
    cin >> n;

    int ans = 0;
    ll l = 1;
    while (l <= n) {
        // compute partial answer for all divisors i >= l
        // s.t. floor(n/i) = floor(n/l)

        ll q = n / l;
        ll r = n / q;
        int len = add(sub(r%md, l%md), 1);
        int sum = mult(mult(add(l%md, r%md), len), inv2);
        ans = add(ans, mult(q % md, sum));
        l = r + 1;
    }

    cout << ans << '\n';
}
