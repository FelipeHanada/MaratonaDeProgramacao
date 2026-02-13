#include <bits/stdc++.h>
using namespace std;


void solve() {
    string p, s;
    cin >> p >> s;
    char last = -1;
    vector<int> diffp, diffs;
    for (auto c : p) {
        if (c == last) {
            diffp.back()++;
        } else {
            diffp.push_back(1);
        }
        last = c;
    }
    last = -1;
    for (auto c : s) {
        if (c == last) {
            diffs.back()++;
        } else {
            diffs.push_back(1);
        }
        last = c;
    }


    if (p[0] != s[0] || diffp.size() != diffs.size()) {
        cout << "NO\n";
        return;
    }

    for (int i=0; i<diffp.size(); i++) {
        if (diffp[i] > diffs[i] || diffs[i] > 2*diffp[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}