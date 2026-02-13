#include <bits/stdc++.h>
using namespace std;

/*
7 3 6

0 1 2 3 1 2 0
^     ^
0 1 2 0 3 2 0
  ^     ^
0 1 2 0 1 2 0
    ^     ^ -> qualquer um vira 3

0 1 2 0 1 2 0
  ^       ^

0 1 0 2
  ^   ^

0 1 2 0 1
0 1 2 0 1 2
0 1 2 0 1 2 0

0 1 2 0 1 3 1
    ^     ^

*/

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    if (n % 3 != 1) {
        for (int i=0; i<n; i++) {
            if (i==y-1 && x+1<y && x%3==y%3) {
                cout << 3 << ' ';
            } else {
                cout << i % 3 << ' ';
            }
        }    
    } else {
        for (int i=0; i<n; i++) {
            int cand = (i == n-1 ? 1 : i%3);
            if (i==y-1 && x+1<y && (x-1)%3==cand) {
                cout << 3 << ' ';
            } else {
                cout << cand << ' ';
            }
        }
    }
    cout << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}