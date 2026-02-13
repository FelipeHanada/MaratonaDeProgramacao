#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 100000;
int prefix[3][MAX_N+1];

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    
    prefix[0][0] = prefix[1][0] = prefix[2][0] = 0;
    for (int i=1; i<=n; i++) {
        int t;
        cin >> t;
        prefix[0][i] = prefix[0][i-1];
        prefix[1][i] = prefix[1][i-1];
        prefix[2][i] = prefix[2][i-1];
        prefix[t-1][i]++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << prefix[0][r] - prefix[0][l-1] << ' ';
        cout << prefix[1][r] - prefix[1][l-1] << ' ';
        cout << prefix[2][r] - prefix[2][l-1] << '\n';
    }
}