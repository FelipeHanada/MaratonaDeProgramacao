#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    ll even = 0;
    vector<int> odd;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x % 2) odd.push_back(x);
        else even += x;
    }

    ll ans = 0;
    if (odd.size()) ans += even;
    sort(odd.begin(), odd.end());
    for (int i=odd.size()/2; i<odd.size(); i++) {
        ans += odd[i];
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