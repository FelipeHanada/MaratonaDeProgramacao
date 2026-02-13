#include <bits/stdc++.h>
using namespace std;


// 2 2 1 1

void solve() {
    int n, in;
    cin >> n;
    vector<int> ans(2*n, -1);
    unordered_set<int> s, inv_s;
    s.insert(0);
    for (int i=1; i<2*n; i++) {
        s.insert(i);
        cout << "? " << s.size() << ' ';
        for (int j : s) cout << j + 1 << ' ';
        cout << '\n';
        fflush(stdout);
        cin >> in;
        if (in != 0) {
            s.erase(i);
            inv_s.insert(i);
            ans[i] = in;
        }
    }

    for (int i : s) {
        cout << "? " << inv_s.size() + 1 << ' ';
        for (int j : inv_s) cout << j + 1 << ' ';
        cout << i + 1 << '\n';
        fflush(stdout);
        cin >> in;
        ans[i] = in;
    }

    cout << "! ";
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
