#include <bits/stdc++.h>
using namespace std;


int solve(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i=0; i<text1.size(); i++) {
        for (int j=0; j<text2.size(); j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);

            if (text1.at(i) == text2.at(j))
                dp[i + 1][j + 1] = dp[i][j] + 1;
        }
    }

    for (int i=0; i<text1.size(); i++)
        dp[i + 1][text2.size()] = max(dp[i + 1][text2.size()], dp[i][text2.size()]);

    for (int j=0; j<text2.size(); j++)
        dp[text1.size()][j + 1] = max(dp[text1.size()][j + 1], dp[text1.size()][j]);

    return dp[text1.size()][text2.size()];
}

int main() {
    cout << solve("abcde", "ace") << "\n";
    cout << solve("abc", "abc") << "\n";
    cout << solve("abc", "def") << "\n";
    cout << solve("bsbininm", "jmjkbkjkv") << "\n";
}

