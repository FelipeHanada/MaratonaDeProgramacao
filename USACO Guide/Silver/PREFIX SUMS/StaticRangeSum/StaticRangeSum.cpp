#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> prefix(n+1, 0);
    for (int i=1; i<n+1; i++) {
        int a;
        cin >> a;
        prefix[i] = prefix[i - 1] + a;
    }

    int l, r;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << endl;
    }
}