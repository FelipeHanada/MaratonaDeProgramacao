#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> count;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    // every subarray has at most count[x]/k for every x
    // we can count this using a two pointer technique

    for (auto [x, c] : count) {
        if (c % k) {
            cout << 0 << '\n';
            return;
        }
    }

    ll ans = 0;

    map<int, int> curr;
    int j=0;
    for (int i=0; i<n; i++) {
        while (j<n && curr[a[j]]+1 <= count[a[j]]/k) {
            curr[a[j]]++;
            j++;
        }
        ans += j - i;
        curr[a[i]]--;
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
