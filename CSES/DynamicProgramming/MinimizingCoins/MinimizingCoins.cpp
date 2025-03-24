#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i=0; i<n; i++)
        cin >> c[i];
    sort(c.begin(), c.end());

    vector<int> dp(x + 1, INT32_MAX >> 1);
    dp[0] = 0;

    for (int i=1; i<=x; i++) {
        for (auto it = c.begin(); it != c.end() && i - *(it) >= 0; it++) {
            dp[i] = min(dp[i], dp[i - *(it)] + 1);
        }
    }
    
    cout << ((dp[x] == (INT32_MAX >> 1)) ? -1 : dp[x]) << "\n";
}
