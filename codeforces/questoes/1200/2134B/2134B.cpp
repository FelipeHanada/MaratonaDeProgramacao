#include <bits/stdc++.h>
using namespace std;


/*
a1, ..., an
we have that: a1+j1*k, ..., an+jn*k
(where ji <= k and represents the number of operations that summed k to ai)

let g = k + 1
we have that j*k = -j mod k+1, then we can guarantee that every ai
    will be multiple of k+1 after at most k operations

precisely, if ai%(k+1) = x, we have to add k exactly x times
*/

#define ll long long


void solve() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        cout << x + k*(x%(k+1)) << ' ';
    }
    cout << '\n';
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
