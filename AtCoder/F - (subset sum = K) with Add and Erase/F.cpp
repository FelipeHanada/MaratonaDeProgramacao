#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;
constexpr int MAX_K = 5000;
int dp[MAX_K + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, k;
    cin >> q >> k;

    fill_n(dp, k + 1, 0);
    dp[0] = 1;

    for (int i=0; i<q; i++) {
        char type; int x;
        cin >> type >> x;

        if (type == '+') {
            for (int j=k; j >= x; j--) {
                dp[j] = (dp[j] + dp[j-x]) % MOD;
            }
        } else {
            for (int j=x; j <= k; j++) {
                dp[j] = (MOD + dp[j] - dp[j-x]) % MOD;
            }
        }

        cout << dp[k] << "\n";
    }
}
