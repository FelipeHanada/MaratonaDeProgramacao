#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, INT32_MAX));
    fill(dp[0].begin(), dp[0].end(), 0);
    fill(dp[1].begin(), dp[1].end(), 1);
    for (int m=2; m<=n; m++) {
        for (int i=0; i+m<=n; i++) {
            dp[m][i] = min(dp[m][i], 1 + dp[m-1][i+1]);
            for (int j=1; j<m; j++) if (s[i+j] == s[i]) {
                dp[m][i] = min(dp[m][i], dp[j-1][i+1] + dp[m-j-1][i+j+1]);
            }
        }
    }

    cout << dp[n][0] << '\n';
}

/*
bababbababa

*/