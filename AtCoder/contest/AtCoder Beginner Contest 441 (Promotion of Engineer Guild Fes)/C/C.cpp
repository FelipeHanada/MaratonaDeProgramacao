#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int i;
    for (i=0; k-1-i >= 0 && x > 0; i++) {
      x -= a[k-1-i];
    }

    if (x > 0) cout << "-1\n";
    else cout << i + n - k << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();    
    return 0;
}
