#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n, q;
    cin >> n >> q;

    vector<ll> prefix(n+1, 0);
    for (int i=0; i<n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
    }

    int offset = 0;
    while (q--) {
        int op, c, l, r;
        cin >> op;
        if (op == 1) {
            cin >> c;
            offset = (offset + c) % n;
        } else {
            cin >> l >> r;
            l += offset;
            r += offset;

            if (l <= n && r <= n) {
                cout << prefix[r] - prefix[l-1] << '\n';
            } else if (l <= n && r > n) {
                cout << prefix[r%n] + prefix[n] - prefix[l-1] << '\n';
            } else if (l > n && r > n) {
                cout << prefix[r%n] - prefix[(l-1)%n] << '\n';
            }
        }
    }
}