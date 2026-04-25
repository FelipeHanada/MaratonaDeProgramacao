#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> prefix(n+1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    prefix[0] = 0;
    for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] + a[i-1];

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << '\n';
    }
}
