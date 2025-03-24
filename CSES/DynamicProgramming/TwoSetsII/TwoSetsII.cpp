#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;


int ext_gcd(int a, int b, int &x, int &y) {
    int x1 = 1, y1 = 0;
    x = 0; y = 1;

    while (b) {
        int q = a / b;
        tie(a, b) = make_tuple(b, a - q * b);
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
    }

    return a;
}


int main() {
    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0 << "\n";
        return 0;
    }

    int k = (n + n*n) / 4; // desired sum
    int dp[k + 1] = {0};
    dp[0] = 1;


    for (int i=1; i<=n; i++) {
        for (int j=k; j>=i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << ((long long)dp[k] * 500000004) % MOD << "\n";
}
