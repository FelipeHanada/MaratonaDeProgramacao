#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int dp[n];
    // dp[i] number of ways to sum the number i + 1
    fill_n(dp, n, 0);
    for (int i=0; i<6 && i<n; i++) {
        dp[i] = 1;
    }

    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0 && j>=i-6; j--) {
            dp[i] = (dp[i] + dp[j]) % (int)(1e9 + 7);
        }
    }

    cout << dp[n - 1] << endl;
}
