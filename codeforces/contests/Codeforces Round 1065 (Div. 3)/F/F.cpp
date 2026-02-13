#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    vector<int> prefix(n), suffix(n);
    prefix.front() = p.front();
    suffix.back() = p.back();
    for (int i=1; i<n; i++) {
        prefix[i] = min(prefix[i-1], p[i]);
        suffix[n-i-1] = max(suffix[n-i], p[n-i-1]);
    }

    vector<pair<int, int>> ans;
    vector<int> blocks;
    for (int i=0; i<n-1; i++) {
        if (prefix[i] > suffix[i+1]) {
            cout << "No\n";
            return;
        }

        if (p[i] == suffix[i])
            ans.push_back({prefix[i], suffix[i+1]});
        else
            ans.push_back({p[i], suffix[i+1]});
    }

    cout << "Yes\n";
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
