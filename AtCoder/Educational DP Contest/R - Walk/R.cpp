#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }


int main() {
    int n; ll k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> a[i][j];

    vector<vector<vector<int>>> dp(63, vector<vector<int>>(n, vector<int>(n, 0)));
    dp[0] = a;

    for (int len=1; len<63; len++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    dp[len][i][j] = add(dp[len][i][j], mult(dp[len-1][i][k], dp[len-1][k][j]));
                }
            }
        }
    }

    vector<vector<int>> curr(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) curr[i][i] = 1;

    for (int x=0; k; x++, k>>=1) {
        if (k & 1) {
            vector<vector<int>> next(n, vector<int>(n, 0));
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    for (int k=0; k<n; k++) {
                        next[i][j] = add(next[i][j], mult(curr[i][k], dp[x][k][j]));
                    }
                }
            }
            swap(next, curr);
        }        
    }

    int ans = 0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) ans = add(ans, curr[i][j]);
    cout << ans << '\n';
}
