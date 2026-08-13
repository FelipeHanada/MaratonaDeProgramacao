#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> phi(N+1);
    iota(phi.begin(), phi.end(), 0);
    for (int i=2; i<=N; i++) if (phi[i] == i) {
        for (int j=i; j<=N; j+=i) {
            phi[j] -= phi[j]/i;
        }
    }

    vector<ll> ans(N+1, 0);
    ans[0] = 0;
    for (ll d=1; d<=N; d++) {
        ans[d]++;
        for (ll n=2*d; n<=N; n+=d) {
            ll m = n/d;
            ans[n] += m * phi[m] / 2;
        }
    }

    int tt;
    cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        cout << n * ans[n] << '\n';
    }
}


/*
lcm(1, n) + lcm(2, n) + ... + lcm(n, n)
lcm(a, n) = a*n/gcd(a, n)

lcmsum(n) = lcm(1, n) + lcm(2, n) + ... + lcm(n, n)
    = sum[i=1..n] i*n/gcd(i,n)
    = n * sum[i=1..n] i/gcd(i,n)
    = n * sum[d s.t. d|n] sum[i=1..n s.t. gcd(i,n)=d] i/d
    = (1)

    let k = i/d and m = n/d
    (1) = n * sum[d s.t. d|n] sum[k <= m s.t. gcd(k,m)=1] k

    if gcd(k, m) = 1, then gcd(m - k, k) = 1
    then sum[k <= m s.t. gcd(k,m)=1] k = sum[k <= m s.t. gcd(k,m)=1] m - k
    2 * sum[k <= m s.t. gcd(k,m)=1] k = sum[k <= m s.t. gcd(k,m)=1] k + m - k
        = sum[k <= m s.t. gcd(k,m)=1] m
    
    then
        sum[k <= m s.t. gcd(k,m)=1] k = 1/2 * sum[k <= m s.t. gcd(k,m)=1] m
            = 1/2 * m * phi(m)
*/ 
