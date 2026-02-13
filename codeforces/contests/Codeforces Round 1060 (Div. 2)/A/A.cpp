#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    int last = -1;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            if (last < max(0, i-k+1)) ans++;
            last = i;
        }
    }

    cout << ans << '\n';
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
