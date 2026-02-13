#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
        char curr;
        cin >> curr;
        prefix[i] = (curr == 'a' ? 1 : -1) + prefix[i-1];
    }

    if (prefix[n] == 0) {
        cout << 0 << '\n';
        return;
    }

    // we want to search the smaller subarray that sum prefix[n]
    // this means, find l and r such that |r-l| is minimal
    //  and prefix[r] - prefix[l] = prefix[n]
    unordered_map<int, int> largest; // largest index that sum x
    largest[0] = 0;
    int ans = INT32_MAX;
    for (int r=1; r<=n; r++) {
        if (largest.count(prefix[r] - prefix[n])) {
            ans = min(ans, r - largest[prefix[r] - prefix[n]]);
        }
        largest[prefix[r]] = r;
    }

    if (ans == n) ans = -1;
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