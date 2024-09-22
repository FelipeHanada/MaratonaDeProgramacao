// https://codeforces.com/contest/852/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;


struct sq_matrix {
    vector<vector<int>> data;
    sq_matrix(int n) {
        data = vector<vector<int>>(n, vector<int>(n, 0));
    }
    int size() const { return data.size(); }
    sq_matrix friend operator*(const sq_matrix &a, const sq_matrix &b) {
        if (a.size() != b.size()) return sq_matrix(0);
        
        int n = a.size();
        sq_matrix r(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    r.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }

        return r;
    }
    vector<int> friend operator*(const sq_matrix &a, const vector<int> &b) {
        if (a.size() != b.size()) return vector<int>();
        int n = a.size();
        vector<int> r(n, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                r[i] += a.data[i][j] * b[i];
            }
        }
        return r;
    }
};

sq_matrix bin_pow(sq_matrix m, int k) {
    sq_matrix r(m.size());
    for (int i=0; i<r.size(); i++) r.data[i][i] = 1;
    
    while (k > 0) {
        if (k & 1)
            r = r * m;
        
        m = m * m;
        k >>= 1;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.in", "r", stdin);

    int n, l, m;
    cin >> n >> l >> m;

    vector<int> a, w, num(m, 0), b;
    sq_matrix transform(m);
    for (int i=0; i<n; i++) { int x; cin >> x; a.push_back(x); }
    for (int i=0; i<n; i++) { 
        int x; cin >> x;
        w.push_back(x);
        num[x]++;

        for (int j=0; j<m; j++) {
            transform.data[j][(j + x) % m] += 1;
        }
    }
    for (int i=0; i<n; i++) { int x; cin >> x; b.push_back(x); }

    // dp[k] = number of paths to the i'th position with length % m = k
    vector<int> dp(m, 0);
    for (int x : a) {
        dp[x % m] += 1;
    }

    transform = bin_pow(transform, l - 2);
    dp = transform * dp;

    // calculate the last step to the final layer manually and then merge with the exit layer
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((j + w[i] + b[i]) % m == 0)
                ans += dp[j];
        }
    }

    cout << ans << endl;
}
