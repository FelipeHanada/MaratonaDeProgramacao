#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9)+7;
inline int add(int a, int b) { return ((a%md) + (b%md)) % md; }

// the only restriction is to not have a triangle
// that is: three elements s.t. a[i] > a[j] > a[k]
// let dp[i][j] = the number of subsequences s.t.
//      the biggest value is a[i]
//      the biggest value (that has a bigger value behind) is a[j]
int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        map<pair<int, int>, ll> dp;
        dp[{INT32_MIN, INT32_MIN}] = 1;
        for (int i=0; i<n; i++) {
            map<pair<int, int>, ll> next;
            for (auto [p, cnt] : dp) {
                next[p] = add(next[p], cnt);

                if (a[i] < p.second) continue;
                if (a[i] >= p.first)
                    next[{a[i], p.second}] = add(next[{a[i], p.second}], cnt);
                else
                    next[{p.first, max(a[i], p.second)}] = add(next[{p.first, max(a[i], p.second)}], cnt);
            }
            swap(dp, next);
        }

        ll ans = 0;
        for (auto [_, x] : dp) ans = add(ans, x);
        cout << ans << '\n';
    }
}
