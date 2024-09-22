#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;


struct matrix {
    vector<vector<ll>> data;
    matrix(int n) {
        data = vector<vector<ll>>(n, vector<ll>(n, 0));
    }
    matrix(int n, int x) {
        data = vector<vector<ll>>(n, vector<ll>(n, x));
    }
    int size() const { return data.size(); }
    ll get(int i, int j) const { return data[i][j]; }
    void set(int i, int j, ll x) { data[i][j] = x; }
    void add(int i, int j, ll x) { data[i][j] = (data[i][j] + x % MOD) % MOD; }
    matrix friend operator*(const matrix &a, const matrix &b) {
        if (a.size() != b.size()) return matrix(0);

        int n = a.size();
        matrix r(n);

        for (int i=0; i<n; i++) {
            for (int j=0;j<n; j++) {
                for (int k=0; k<n; k++) {
                    r.add(i, j, a.get(i, k) * b.get(k, j));
                }
            }
        }

        return r;
    }
};

matrix bin_pow(matrix m, ll k) {
    matrix r(m.size());
    for (int i=0; i<m.size(); i++) r.set(i, i, 1);

    while (k > 0) {
        if (k & 1)
            r = r * m;

        m = m * m;
        k >>= 1;
    }
    return r;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    matrix adj(m, 1);
    for (int i=0; i<k; i++) {
        char a, b;
        cin >> a >> b;
        a -= (a >= 'a') ? 'a' : 'A' - 26;
        b -= (b >= 'a') ? 'a' : 'A' - 26;
        adj.set(a, b, 0);
    }

    matrix r = bin_pow(adj, n - 1);
    ll ans = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m;j++) {
            ans = (ans + r.get(i, j)) % MOD;
        }
    }
    cout << ans << endl;
}
