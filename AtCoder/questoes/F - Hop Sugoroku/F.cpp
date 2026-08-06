#include <bits/stdc++.h>
using namespace std;

constexpr int md = 998244353;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int x = sqrt(n);
    vector<vector<int>> s(x+1, vector<int>(x+1, 0));
    vector<int> dp(n, 1);
    for (int i=n-1; i>=0; i--) {
        if (a[i] <= x) {
            dp[i] = add(dp[i], s[a[i]][i % a[i]]);
        } else {
            for (int j=i+a[i]; j<n; j+=a[i]) {
                dp[i] = add(dp[i], dp[j]);
            }
        }

        for (int j=1; j<=x; j++) {
            s[j][i%j] = add(s[j][i%j], dp[i]);
        }
    }

    cout << dp[0] << '\n';
}
