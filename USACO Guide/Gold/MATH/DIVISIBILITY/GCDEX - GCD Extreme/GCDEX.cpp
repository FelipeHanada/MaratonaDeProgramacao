#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1000000;

int main() {
    vector<ll> phi(N+1);
    iota(phi.begin(), phi.end(), 0);
    for (int i=2; i<=N; i++) if (phi[i] == i) {
        for (int j=i; j<=N; j+=i) {
            phi[j] -= phi[j]/i;
        }
    }

    vector<ll> part(N+1, 0);
    for (int d=1; d<=N; d++) {
        for (int k=d; k<=N; k+=d) {
            part[k] += d * phi[k / d];
        }
    }

    vector<ll> ans(N+1, 0);
    for (int i=1; i<=N; i++) {
        ans[i] = ans[i-1] + part[i] - i;
    }

    while (1) {
        int n; cin >> n;
        if (!n) break;

        cout << ans[n] << '\n';
    }
}


/*
ans(n) = sum[1 <= i < n] sum[i < j <= n] gcd(i, j)


for a fixed k = j, we have
    sum[1 <= i < k] gcd(i, k)
    = sum[1 <= i <= k] gcd(i, k)  - k

lets compute sum[1 <= i <= k] gcd(i, k)
    let d = gcd(i, k), we can rewrite the above as
    sum[1 <= d <= k] sum[1 <= i <= k s.t. gcd(i, k) = d] d

    let x = i/d and y = k/d

    sum[1 <= d <= k s.t. d|k] sum[1 <= x <= y s.t. gcd(x, y) = 1] d
    = sum[1 <= d <= k s.t. d|k] sum[i=1..phi(y)] d
    = sum[1 <= d <= k s.t. d|k] d phi(y)
    = sum[1 <= d <= k s.t. d|k] d phi(k/d)
    this can be computed in a sieve-like way
*/
