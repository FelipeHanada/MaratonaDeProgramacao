#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> sw;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sw.insert(x);
    }
    vector<int> a(m), b(m);
    for (int i=0; i<m; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    vector<pair<int, int>> st1;
    vector<int> st2;
    for (int i=0; i<m; i++) {
        if (b[i] == 0) st2.push_back(a[i]);
        else st1.push_back({a[i], b[i]});
    }
    sort(st1.begin(), st1.end());

    int ans = 0;
    for (int i=0; i<st1.size(); i++) {
        auto it = lower_bound(sw.begin(), sw.end(), st1[i].first);
        if (it != sw.end()) {
            ans++;
            sw.erase(it);
            sw.insert(max(*it, st1[i].second));
        }
    }

    for (int i=0; i<st2.size(); i++) {
        auto it = lower_bound(sw.begin(), sw.end(), st2[i]);
        if (it != sw.end()) {
            ans++;
            sw.erase(it);
        }
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
