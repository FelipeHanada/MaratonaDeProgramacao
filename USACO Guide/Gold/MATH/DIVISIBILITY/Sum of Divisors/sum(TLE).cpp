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
    auto solve = [&](ll k) -> ll {
        // compute partial answer for all divisors i >= k
        // s.t. floor(n/i) = floor(n/k)

        ll l = k, r = n+1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (n/mid == n/k) l = mid;
            else r = mid;
        }

        int d = (n/k)%md;
        int sum = mult(mult(add(k, l), sub(r, k)), inv2);
        ans = add(ans, mult(d, sum));

        return r;
    };

    ll i = 1;
    while (i <= n) i = solve(i);
    cout << ans << '\n';
}
