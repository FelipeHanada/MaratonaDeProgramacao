#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1e6;
int dp[MAX_N + 1];

int main() {
    int n;
    cin >> n;

    dp[0] = 0;
    for (int i=1; i<=n; i++) {

        dp[i] = INT32_MAX >> 1;
        for (int j=i; j; j /= 10) {
            dp[i] = min(dp[i], dp[i - j % 10] + 1);
        }

    }

    cout << dp[n] << "\n";
}
