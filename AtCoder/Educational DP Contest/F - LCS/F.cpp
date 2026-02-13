#include <bits/stdc++.h>
using namespace std;


int main() {
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    for (int i=1; i<=s.size(); i++) {
        for (int j=1; j<=t.size(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    stack<char> ans;
    int i=s.size(), j=t.size();
    while (i>0 && j>0) {
        if (s[i-1] == t[j-1]) {
            ans.push(s[i-1]);
            i--;
            j--;
        } else if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            j--;
        }
    }

    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}
