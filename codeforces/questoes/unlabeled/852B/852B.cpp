#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }

int n, l, m;
vector<int> a, b, c;
vector<int> dp;
vector<vector<int>> matrix, aux;
vector<vector<int>> mult(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    vector<vector<int>> ans(m, vector<int>(m, 0));
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<m; k++) {
                ans[i][j] = add(ans[i][j], mult(a[i][k], b[k][j]));
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> l >> m;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) cin >> c[i];

    dp.assign(m, 0);
    for (int i=0; i<n; i++) dp[a[i]%m]++;

    matrix.assign(m, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrix[(j+b[i])%m][j]++;
        }
    }

    aux.assign(m, vector<int>(m, 0));
    for (int i=0; i<m; i++) aux[i][i] = 1;

    l -= 2;
    while (l) {
        if (l & 1) aux = mult(aux, matrix);
        matrix = mult(matrix, matrix);
        l >>= 1;
    }

    vector<int> next(m, 0);
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            next[i] = add(next[i], mult(aux[i][j], dp[j])); 
        }
    }

    swap(dp, next);
    next.assign(m, 0);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            next[(j+b[i]+c[i])%m] = add(next[(j+b[i]+c[i])%m], dp[j]);
        }
    }

    cout << next[0] << '\n';
}
