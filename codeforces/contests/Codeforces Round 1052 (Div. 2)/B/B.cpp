#include <bits/stdc++.h>
using namespace std;

// 1. can we get there choosing all sets?
// 2. can we get there by choosing all sets except one? (we should be able to get using two distinct sets)

bool test(vector<int>& v) {
    for (int x : v) {
        if (!x) return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> count(m, 0);
    vector<vector<int>> sets(n);
    for (int i=0; i<n; i++) {
        int a, x;
        cin >> a;
        for (int j=0; j<a; j++) {
            cin >> x; x--;
            count[x]++;
            sets[i].push_back(x);
        }
    }

    int ans = 0;
    if (test(count)) ans++;
    for (int i=0; i<n && ans < 3; i++) {
        for (int x : sets[i]) count[x]--;
        if (test(count)) ans++;
        for (int x : sets[i]) count[x]++;
    }

    cout << (ans == 3 ? "YES" : "NO") << '\n';
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
