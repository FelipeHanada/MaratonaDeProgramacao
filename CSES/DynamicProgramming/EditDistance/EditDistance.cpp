#include <bits/stdc++.h>
using namespace std;


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i=0; i<=s1.size(); i++)
        dp[i][0] = i;
    for (int j=0; j<=s2.size(); j++)
        dp[0][j] = j;

    for (int i=0; i<s1.size(); i++) {
        for (int j=0; j<s2.size(); j++) {
            dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
            if (s1.at(i) == s2.at(j))
                dp[i+1][j+1] = dp[i][j];
        }
    }

    cout << dp[s1.size()][s2.size()] << "\n";
}
