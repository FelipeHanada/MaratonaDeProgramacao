#include <bits/stdc++.h>
using namespace std;


/*
n * m = k
therefore n or m divides k

*/


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n % k == 0 || m % k == 0) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << 1 + ((i + j) % k) << ' ';
            }
            cout << '\n';
        }
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << 1 + ((i+j*n) % k) << ' '; 
        }
        cout << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}