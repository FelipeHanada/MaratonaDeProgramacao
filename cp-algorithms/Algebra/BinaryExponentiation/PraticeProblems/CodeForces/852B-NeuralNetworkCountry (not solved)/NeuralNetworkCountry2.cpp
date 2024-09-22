// https://codeforces.com/contest/852/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.in", "r", stdin);

    int n, l, m;
    cin >> n >> l >> m;

    vector<int> a, w, num(m, 0), b;
    for (int i=0; i<n; i++) { int x; cin >> x; a.push_back(x); }
    for (int i=0; i<n; i++) { 
        int x; cin >> x;
        w.push_back(x);
        num[x]++;
    }
    for (int i=0; i<n; i++) { int x; cin >> x; b.push_back(x); }

    // dp[k] = number of paths to the i'th position with length % m = k
    vector<int> dp(m, 0), dp_temp(m);
    for (int x : a) {
        dp[x % m] += 1;
    }

    for (int i=0; i<l-2; i++) {
        fill_n(dp_temp.begin(), m, 0);
        for (int j=0; j<m; j++) {
            for (int k=0; k<m; k++) {
                dp_temp[j] += num[k] * dp[abs((j - k) % m)];
            }
        }
        dp = dp_temp;
    }

    // calculate the last step to the final layer manually and then merge with the exit layer
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((j + w[i] + b[i]) % m == 0)
                ans += dp[j];
        }
    }

    cout << ans << endl;
}
