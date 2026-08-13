#include <bits/stdc++.h>
using namespace std;

constexpr int md = 998244353;
inline int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

constexpr int MAX_N = 1000;
int dp[MAX_N+1][10][10][10];

int main() {
    int n; string s1, s2, s3;
    cin >> n >> s1 >> s2 >> s3;

    // dp[n][i][j][k] = number of strings of size n
    // that contain the subsequences s1[1..i], s2[1..j] and s3[1..k]

    for (int m=1; m<=n; m++)
    for (int i=0; i<s1.size(); i++)
    for (int j=0; j<s2.size(); j++)
    for (int k=0; k<s3.size(); k++) {
        dp[m][i][j][k] = 0;
    }
    dp[0][0][0][0] = 1;
    for (int m=0; m<n; m++)
    for (int i=0; i<s1.size(); i++)
    for (int j=0; j<s2.size(); j++)
    for (int k=0; k<s3.size(); k++) {
        for (char c = 'a'; c <= 'z'; c++) {
            int ii = i, jj = j, kk = k;
            if (c == s1[i]) ii++;
            if (c == s2[j]) jj++;
            if (c == s3[k]) kk++;
            if (ii >= s1.size() || jj >= s2.size() || kk >= s3.size()) continue;

            dp[m+1][ii][jj][kk] = add(dp[m+1][ii][jj][kk], dp[m][i][j][k]);
        }
    }

    int ans = 0;
    for (int i=0; i<s1.size(); i++)
    for (int j=0; j<s2.size(); j++)
    for (int k=0; k<s3.size(); k++) {
        ans = add(ans, dp[n][i][j][k]);
    }
    cout << ans << '\n';
}