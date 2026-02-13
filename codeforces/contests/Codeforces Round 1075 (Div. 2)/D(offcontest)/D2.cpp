#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int MOD = 1e9+7;

void solve() {
    int n, c; string s;
    cin >> n >> c >> s;

    if (s.front() == '0' || s.back() == '0') {
        cout << "-1\n";
        return;
    }

    vector<int> even, odd;
    int ans = 1;
    for (int i=0; i<n-1; i++) {
        int k = 1;
        if (s[i] == '0') k = i;
        else if (s[i] == '1') k = 2;
        else if (i != 1) {
            if (i % 2) odd.push_back(i);
            else even.push_back(i);
        }

        c /= __gcd(c, k);
        ans = ((ll) ans * k) % MOD;
    }

    if (__builtin_popcount(c) == 1) {
        for (int i=0; c > 1 && i<even.size(); i++) {
            ans = ((ll) ans * 2) % MOD;
            c /= 2;
        }
        for (int i=odd.size()-1; i >= 0; i--) {
            if (c > 2) {
                ans = ((ll) ans * 2) % MOD;
                c /= 2;
            } else {
                ans = ((ll) ans * odd[i]) % MOD;
            }
        }
    } else {
        for (int i=0; i<even.size() + odd.size(); i++) {
            ans = ((ll) ans * 2) % MOD;
        }
    }

    if (c == 1) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}