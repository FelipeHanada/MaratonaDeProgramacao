#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 1e5;
vector<int> divs[MAX_N+1];
void precompute() {
    for (int i=2; i<=MAX_N; i++) {
        for (int j=i; j<=MAX_N; j+=i) {
            divs[j].push_back(i);
        }
    }
}

// vector<vector<int>> pos(MAX_N+1);
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    // pos.assign(MAX_N+1, {});
    map<int, vector<int>> pos;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    while (q--) {
        ll k;
        int l, r;
        cin >> k >> l >> r; l--;

        vector<int> changes;
        for (int& d : divs[k]) {
            auto lb = lower_bound(pos[d].begin(), pos[d].end(), l);
            if (lb != pos[d].end() && *lb < r) {
                changes.push_back(*lb);
            }
        }
        sort(changes.begin(), changes.end());

        ll ans = 0;
        int last = l;
        for (auto& x : changes) {
            ans += (x - last) * k;
            while (k % a[x] == 0) k /= a[x];
            last = x;
        }
        ans += (r - last) * k;
        cout << ans << '\n';
    }
}

int  main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}