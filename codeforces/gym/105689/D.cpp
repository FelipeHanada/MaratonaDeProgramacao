#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD (int) (1e9 + 7)
#define K_MAX (int) (1e5 + 1)

int egcd(int a, int b, int *x, int *y) {
    *x = 1;
    *y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;

    while (b1) {
        int q = a1 / b1;
        tie(*x, x1) = make_tuple(x1, *x - q * x1);
        tie(*y, y1) = make_tuple(y1, *y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int mod_inv(int a) {
    int x, y;
    int g = egcd(a, MOD, &x, &y);
    int teste = (x % MOD + MOD) % MOD;
    return (x % MOD + MOD) % MOD;
}

int fac[K_MAX];
void setup() {
    fac[0] = 1;
    for (int i=1; i<K_MAX; i++) {
        fac[i] = ((ll) fac[i - 1] * i) % MOD;
    }
}

int solve(int n, int m, vector<int> &k) {
    int ans = 1;
    int n_mod_inv = mod_inv(fac[n]);

    for (int i=0; i<m; i++) {
        ans = ((ll) ans * fac[k[i]]) % MOD;
        ans = ((ll) ans * n_mod_inv) % MOD;
        ans = ((ll) ans * mod_inv(fac[k[i] - n])) % MOD;
    }

    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> k(m);
    for (int i=0; i<m; i++)
        cin >> k[i];

    setup();
    cout << solve(n, m, k) << "\n";
}