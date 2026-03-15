#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 30;

int main() {
    vector<vector<int>> dp(MAX_N+1, vector<int>(MAX_N*(MAX_N-1)/2+1, -1));
    // dp[i][j] = size of the last sorted segment taken
    //            such that the current permutation of size i
    //            has exactly j pairs (x,y) of sorted segments
    dp[0][0] = 0;
    for (int i=0; i<=MAX_N; i++) {
        for (int j=0; j<=MAX_N*(MAX_N-1)/2; j++) {
            if (dp[i][j] == -1) continue;

            for (int k=1; k+i<=MAX_N; k++) { // size of the next sorted segment
                dp[i+k][j + k*(k-1)/2] = k;
            }
        }
    }

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;

        int target = n*(n-1)/2 - k;
        if (dp[n][target] == -1) {
            cout << "0\n";
        } else {
            int last = n+1;
            int i = n;
            int j = target;
            while (last > 1) {
                for (int x=last-dp[i][j]; x<last; x++) {
                    cout << x << ' ';
                }
                last = last-dp[i][j];
                tie(i, j) = make_tuple(i-dp[i][j], j - dp[i][j]*(dp[i][j]-1)/2);
            }
            cout << '\n';
        }
    }
}