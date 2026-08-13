#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> a[i][j];

    vector<ll> partial(1<<n, 0);
    for (int mask=1; mask<(1<<n); mask++) {
        int i = __builtin_ffs(mask) - 1;
        partial[mask] = partial[mask^(1<<i)];
        for (int j=0; j<n; j++) if (j != i && (mask&(1<<j))) {
            partial[mask] += a[i][j];
        }
    }

    vector<ll> dp(1<<n, 0);
    for (int mask=1; mask<(1<<n); mask++) {
        for (int submask=mask; submask; submask = (submask-1)&mask) {
            dp[mask] = max(dp[mask], dp[mask&(~submask)] + partial[submask]);
        }
    }

    cout << dp[(1<<n)-1] << '\n';
}


/*
*/