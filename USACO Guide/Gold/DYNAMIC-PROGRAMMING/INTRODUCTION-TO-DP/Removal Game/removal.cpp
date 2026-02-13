#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 5000;
int n;
int a[MAX_N];
ll prefix[MAX_N+1];
ll dp[MAX_N][MAX_N];
// dp[i][j] best sum the first player can sum in the subarray i..j

int main() {
    cin >> n;

    prefix[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        prefix[i+1] = prefix[i] + a[i];
    }

    for (int i=0; i<n; i++) dp[i][i] = a[i];
    for (int s=1; s<n; s++) {
        for (int i=0; i+s<n; i++) {
            dp[i][i+s] = max(
                a[i] + prefix[i+s+1] - prefix[i+1] - dp[i+1][i+s],
                a[i+s] + prefix[i+s] - prefix[i] - dp[i][i+s-1]
            );
        }
    }

    cout << dp[0][n-1] << '\n';
}