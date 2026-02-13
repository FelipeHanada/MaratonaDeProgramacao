#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    vector<int> ans(n);
    for (int i=0; i<n; i++) ans[(x+i)%n] = i%2;
    if (!((y-x)%2) || n % 2) ans[x] = 2;

    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
