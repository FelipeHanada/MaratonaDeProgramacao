#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;

    // PRECOMPUTATION
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << '\n';
    }
}
