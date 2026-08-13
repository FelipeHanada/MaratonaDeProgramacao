#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int md = int(1e9)+7;
int add(ll a, ll b, int m) { return ((a%m) + (b%m)) % m; }
int sub(ll a, ll b, int m) { return ((a%m) - (b%m) + m) % m; }
int mult(ll a, ll b, int m) { return (ll(a%m) * (b%m)) % m; }
int add(ll a, ll b) { return add(a, b, md); }
int sub(ll a, ll b) { return sub(a, b, md); }
int mult(ll a, ll b) { return mult(a, b, md); }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
int inv(int a) { return binpow(a, md-2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int p, a;

    int cnt = 1, cntpower = 1, sum = 1, prod = 1;
    for (int i=0; i<n; i++) {
        cin >> p >> a;

        prod = mult(
            binpow(prod, a+1),
            binpow(p, mult(((ll(a)*a + a) / 2), cntpower, md-1))
        );

        cnt = mult(cnt, a + 1);
        cntpower = mult(cntpower, a + 1, md-1);
        sum = mult(sum, mult(sub(binpow(p, a+1), 1), inv(sub(p, 1))));
    }

    cout << cnt << ' ' << sum << ' ' << prod << '\n';
}

/*
let prev[i] = product of all divisors d of N
            s.t. d factorization only have primes up to pi

1
1 | 2 4
1 | 2 4 | 3 6 12

prev[i] = 
    prev[i-1]
    prev[i-1] * pi^(1 * cnt[i-1])
    prev[i-1] * pi^(2 * cnt[i-1])
    ...
    prev[i-1] * pi^(ai * cnt[i-1])
    = prev[i-1]^(ai+1) * pi^(sum 1..ai * cnt[i-1])
*/
