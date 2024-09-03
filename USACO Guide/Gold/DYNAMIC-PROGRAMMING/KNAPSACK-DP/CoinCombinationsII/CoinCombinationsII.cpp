#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 100;
constexpr int MAX_X = 1e6;
int n, x, c[MAX_N];
int dp[MAX_X + 1];

int main() {
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> c[i];
    sort(c, c + n);

    dp[0] = 1;
    fill_n(dp + 1, x, 0);

    for (int ci=0; ci<n; ci++) {
        for (int i=1; i<=x; i++) {
            if (i - c[ci] < 0) continue;
            dp[i] += dp[i - c[ci]];
            dp[i] %= (int) 1e9 + 7;
        }
    }

    cout << dp[x] << endl;
}