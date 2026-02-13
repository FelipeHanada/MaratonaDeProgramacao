#include <bits/stdc++.h>
using namespace std;



void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    int l1 = min(m, -l);
    cout << -l1 << ' ' << m - l1 << '\n';
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