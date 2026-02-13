#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }

    vector<pair<int, int>> dp(1<<n, {n, 0});
    dp[0] = {1, 0};
    for (int s=1; s<1<<n; s++) {
        for (int i=0; i<n; i++) if (s&(1<<i)) {
            auto option = dp[s^(1<<i)];
            if (option.second + w[i] <= x) {
                option.second += w[i];
            } else {
                option.first += 1;
                option.second = w[i];
            }
            dp[s] = min(dp[s], option);
        }
    }

    cout << dp[(1<<n)-1].first << '\n';
}
