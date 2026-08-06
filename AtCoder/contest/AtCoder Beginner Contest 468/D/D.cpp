#include <bits/stdc++.h>
using namespace std;



int main() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT32_MAX));
    for (int i=0; i<=n; i++) dp[0][i] = 0;
    for (int i=0; i<n; i++) dp[1][i] = 0;

    for (int len=2; len<=n; len++) {
        for (int i=0; i+len<=n; i++) {
            dp[len][i] = dp[len-2][i+1] + int(s[i] != s[i+len-1]);
        }
    }

    int ans = 0;
    for (int len=1; len<=n; len++) {
        for (int i=0; i+len<=n; i++) {
            ans += int(dp[len][i] <= 1);            
        }
    }

    cout << ans << '\n';
}
