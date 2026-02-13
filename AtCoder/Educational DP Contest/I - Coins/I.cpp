#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<double> dp(n+1, 0); // dp[i] = probability to get i heads
    double p;
    dp[0] = 1;
    for (int i=0; i<n; i++) {
        cin >> p;
        for (int j=n; j>0; j--) {
            dp[j] = dp[j] * (1 - p) + dp[j-1] * p;
        }
        dp[0] *= 1 - p;
    }

    double ans = 0;
    for (int i=(n+1)/2; i<=n; i++) {
        ans += dp[i];
    }
    cout << setprecision(9) << ans << '\n';
}
