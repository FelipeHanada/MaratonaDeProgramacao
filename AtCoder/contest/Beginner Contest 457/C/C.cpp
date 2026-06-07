#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        a[i].resize(l);
        for (int j=0; j<l; j++) cin >> a[i][j];
    }
    vector<ll> c(n);
    for (int i=0; i<n; i++) cin >> c[i];

    k--; // <---- k pra ser 0-indexado
    int i = 0;
    while (k >= a[i].size()) {
        int amount = min(c[i], k / ll(a[i].size()));
        c[i] -= amount;
        k -= amount * a[i].size();
        if (c[i] == 0) i++;
    }

    cout << a[i][k] << '\n';
}
