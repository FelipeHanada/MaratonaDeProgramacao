// https://codeforces.com/contest/852/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, m;
    cin >> n >> l >> m;

    vector<int> entry, layer, exit;
    for (int i=0; i<n; i++) { int x; cin >> x; entry.push_back(x); }
    for (int i=0; i<n; i++) { int x; cin >> x; layer.push_back(x); }
    for (int i=0; i<n; i++) { int x; cin >> x; exit.push_back(x); }

    // dp[k] = number of paths to the i'th position with length % m = k
    vector<int> dp(m, 0), dp_temp(m);
    for (int x : entry) {
        dp[x % m] += 1;
    }

    for (int i=0; i<l-2; i++) {
        fill_n(dp_temp.begin(), m, 0);
        for (int j=0; j<m; j++) {
            for (int x : layer) {
                dp_temp[(j + x) % m] = (dp_temp[(j + x) % m] + dp[j]) % MOD;
            }
        }
        dp = dp_temp;
    }

    // calculate the last step to the final layer manually and then merge with the exit layer
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((j + layer[i] + exit[i]) % m == 0)
                ans += dp[j];
        }
    }

    cout << ans << endl;
}
