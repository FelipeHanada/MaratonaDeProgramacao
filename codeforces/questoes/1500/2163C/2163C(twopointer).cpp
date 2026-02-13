#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a[2] = { vector<int>(n), vector<int>(n) };
    for (int i=0; i<n; i++) cin >> a[0][i];
    for (int i=0; i<n; i++) cin >> a[1][i];
    map<int, vector<pair<int, int>>> m;
    for (int i=0; i<n; i++) m[a[0][i]].push_back({0, i});
    for (int i=0; i<n; i++) m[a[1][i]].push_back({1, i});
   
    ll ans = 0;
    set<int> s[2];
    s[0].insert(n);
    for (int i=0; i<n; i++) s[0].insert(i);
    s[1].insert(-1);
    for (int i=0; i<n; i++) s[1].insert(i);
    
    int l = 0;
    for (int r=1; r<=2*n; r++) {
        for (auto [row, i] : m[r]) s[row].erase(i);

        while (l < r && *s[0].begin() - 1 > *s[1].rbegin()) {
            l++;
            for (auto [row, i] : m[l]) s[row].insert(i);
        }

        ans += l;
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