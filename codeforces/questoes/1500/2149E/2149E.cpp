#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    map<int, int> w1;
    map<int, int> w2;
    ll ans = 0;
    int i, j1, j2; i = j1 = j2 = 0;
    while (i < n) {
        while (j1 < n && w1.size() < k) {
            w1[a[j1++]]++;
        }
        while (j2 < n && (w2.size() < k || w2.count(a[j2]))) {
            w2[a[j2++]]++;
        }

        if (w1.size() < k) break;
        if (j2-i >= l && j1-i <= r)
            ans += 1 + min(r, j2-i) - max(l, j1-i);

        if (--w1[a[i]] == 0) w1.erase(a[i]);
        if (--w2[a[i]] == 0) w2.erase(a[i]);
        i++;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}