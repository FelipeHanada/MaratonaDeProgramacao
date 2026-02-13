#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    char c;
    vector<bool> s1(n), s2(n);
    for (int i=0; i<n; i++) {
        cin >> c;
        s1[i] = c == 'B';
    }
    for (int i=0; i<n; i++) {
        cin >> c;
        s2[i] = c == 'B';
    }

    bool v1 = s1[0], v2 = s2[0];

    for (int i=1; i<n; i++) {
        if (s1[i] && s2[i]) {
            tie(v1, v2) = make_tuple(v2, v1);
        } else if (!s1[i]) {
            v1 = false;
        } else if (!s2[i]) {
            v2 = false;
        }
    }

    cout << (v1 || v2 ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}