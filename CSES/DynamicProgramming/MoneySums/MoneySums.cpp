#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x[100];

    cin >> n;

    int k = 0;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        k += x[i];
    }

    bool dp[k + 1];
    fill_n(dp, k + 1, false);
    dp[0] = true;

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=k; j>=x[i]; j--) {
            if (!dp[j] && dp[j - x[i]]) {
                dp[j] = true;
                ans++;
            }
        }
    }

    cout << ans << "\n";
    for (int i=1; i<=k; i++) {
        if (dp[i])
            cout << i << " ";
    }
}
