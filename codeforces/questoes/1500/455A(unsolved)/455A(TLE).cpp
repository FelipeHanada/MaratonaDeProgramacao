#include <bits/stdc++.h>
using namespace std;


/*
we can sort the array in same-value parts
every sequencial part can be partitioned in groups of 2 or 3


1 1 1 1 1 2 2 2 2 3 3 3 | 6 6 6 6 7 7 7 8 8 8 9 | 11 | 20 |
L                       L                       L    L    R
*/

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, ll> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<pair<int, ll>> k(m.begin(), m.end());

    ll ans = 0;
    int l=0, r=1;
    int last = k[0].first;
    vector<ll> dp(n+1);
    while (l < k.size()) {
        dp[0] = 0;
        dp[1] = k[l].first * k[l].second;
        int i=2;
        while (r < k.size() && k[r].first <= last + 1) {
            last = k[r++].first;
            dp[i] = max(dp[i-1], dp[i-2] + k[l+i-1].first * k[l+i-1].second);
            i++;
        }

        ans += dp[r-l];
        l = r;
    }

    cout << ans << '\n';
}
