#include <bits/stdc++.h>
using namespace std;


constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    vector<int> dp(1<<n, 0); dp[0] = 1;
    for (int i=0; i<n; i++) {
        for (int mask=0; mask<(1<<n); mask++) if (__builtin_popcount(mask) == i + 1) {

            for (int j=0; j<n; j++) if (((1<<j) & mask) && a[i][j]) {
                dp[mask] = add(dp[mask], dp[mask ^ (1<<j)]);
            }

        }
    }

    cout << dp[(1<<n)-1] << '\n';
}


/*
O(n^2 * 2^n)
*/