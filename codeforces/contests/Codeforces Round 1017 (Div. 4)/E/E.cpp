#include <bits/stdc++.h>
using namespace std;


#define ll long long


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bitcount(32, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        int x = a[i];
        for (int j=0; x; j++) {
            if (x & 1) bitcount[j]++;
            x >>= 1;
        }
    }

    int best = -1;
    ll bestD = INT64_MIN;
    for (int i=0; i<n; i++) {
        ll currD = 0;
        for (int j=0; j<32; j++) {
            if (a[i] & (1<<j)) {
                currD += (ll)(n-bitcount[j])*(1<<j) - (ll)bitcount[j]*(1<<j);
            }
        }

        if (currD > bestD) {
            bestD = currD;
            best = i;
        }
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += a[best] ^ a[i];
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}