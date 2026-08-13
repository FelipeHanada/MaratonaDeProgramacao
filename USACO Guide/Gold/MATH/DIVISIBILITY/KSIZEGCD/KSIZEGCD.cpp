#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<map<int, int>> m(n);
        // m[i][g] = maximum length of a subarray that ends on i and have gcd = g
        // m[i].size() is bounded by log max A
        // since m[i] stores all possible gcd's from A[..i]
        // proof: starting from A[i..i] and extending left
        // at each step the gcd can only change to some of its divisors
        // then gcd can change O(log A[i]) times
        m[0][a[0]] = 1;
        for (int i=1; i<n; i++) {
            m[i][a[i]] = 1;
            for (auto [g, len] : m[i-1]) {
                m[i][gcd(g, a[i])] = max(m[i][gcd(g, a[i])], len + 1);
            }
        }

        vector<int> ans(n+1, -1);
        for (int i=0; i<n; i++) {
            for (auto [g, len] : m[i]) {
                ans[len] = max(ans[len], g);
            }
        }

        for (int i=1; i<=n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}
