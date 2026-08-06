#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> a(h);
    for (int i=0; i<h; i++) cin >> a[i];

    vector<vector<int>> prefix(h+1, vector<int>(w, 0));
    for (int i=1; i<=h; i++) {
        for (int j=0; j<w; j++) {
            prefix[i][j] = prefix[i-1][j] + int(a[i-1][j] == '1');
        }
    }

    ll ans = 0;
    for (int low=0; low<h; low++) {
        for (int high=low+1; high<=h; high++) {
            auto f = [&](int i) {
                return prefix[high][i] - prefix[low][i];
            };

            auto g = [&](int k) -> ll {
                // count the number of pairs (l, r)
                // s.t. l <= r and sum[l..r] >= k

                ll ans = 0;
                int l = 0, r = 0;
                int sum = 0;
                while (l < w) {
                    while (r < w && sum + f(r) < k) sum += f(r++);
                    ans += w - r;
                    sum -= f(l++);
                    if (r < l) sum += f(r++);
                }

                return ans;
            };

            ans += g(k) - g(k+1);
        }
    }

    cout << ans << '\n';
}