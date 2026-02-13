#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    int a = 0, b = 0;
    set<int> c;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == -1) a++;
        else if (x == -2) b++;
        else c.insert(x-1);
    }

    vector<int> prefix(m+1, 1);
    prefix[0] = 0;
    for (int x : c) prefix[x+1]--;
    for (int i=1; i<=m; i++) prefix[i] += prefix[i-1];

    int ans = min(prefix[m], max(a, b));
    for (int i : c) {
        ans = max(ans, min(prefix[i], a) + min(prefix[m] - prefix[i], b));
    }

    cout << c.size() + ans << '\n';
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