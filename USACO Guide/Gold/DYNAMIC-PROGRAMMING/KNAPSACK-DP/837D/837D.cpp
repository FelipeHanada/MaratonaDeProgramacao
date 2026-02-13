#include <bits/stdc++.h>
using namespace std;


#define ll long long

void decomp(ll x, int& a, int& b) {
    for (b = 0; x % 5 == 0; b++) {
        x /= 5;
    }
    a = __builtin_ctzll(x);
}


int n, k;
constexpr int MAX_N = 200;
constexpr int MAX_LOG = 200*64;
int dp[MAX_N+1][MAX_LOG];


int main() {
    cin >> n >> k;

    // we define dp[i][j][l] as the maximum amount of 5's
    // that you can get with the elements 1..i, using j and with l 2's

    for (int i=0; i<=n; i++) {
        fill_n(dp[i], MAX_LOG, -1);
    }
    dp[0][0] = 0;

    ll x; int a, b;
    for (int i=0; i<n; i++) {
        cin >> x;
        decomp(x, a, b);

        for (int j=n; j>0; j--) {
            for (int l=MAX_LOG-1; l>=a; l--) {
                if (dp[j-1][l-a] < 0) continue;
                dp[j][l] = max(dp[j][l], dp[j-1][l-a] + b);
            }
        }
    }

    int ans = 0;
    for (int l=0; l<MAX_LOG; l++) {
        ans = max(ans, min(l, dp[k][l]));
    }
    cout << ans << '\n';
}
