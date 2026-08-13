#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int md = int(1e9)+7;
int mult(int a, int b) {
    return (ll(a) * b) % md;
}
int bin_exp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}

constexpr int N = int(1e6);
int fact[N+1], inv[N+1];
void precompute() {
    fact[0] = 1;
    for (int i=1; i<=N; i++) fact[i] = mult(fact[i-1], i);
    inv[N] = bin_exp(fact[N], md-2);
    for (int i=N-1; i>=0; i--) {
        inv[i] = mult(inv[i+1], i+1);
    }
}


int main() {
    precompute();

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << mult(mult(fact[a], inv[b]), inv[a - b]) << '\n';
    }
}