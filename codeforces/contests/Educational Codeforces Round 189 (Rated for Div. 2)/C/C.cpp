#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        vector<int> dp(n+1);
        dp[0] = 0; dp[1] = a[0] != b[0];
        for (int i=2; i<=n; i++) {
            dp[i] = min(
                dp[i-1] + int(a[i-1] != b[i-1]),
                dp[i-2] + int(a[i-2] != a[i-1]) + int(b[i-2] != b[i-1])
            );
        }

        cout << dp[n] << '\n';
    }
}
