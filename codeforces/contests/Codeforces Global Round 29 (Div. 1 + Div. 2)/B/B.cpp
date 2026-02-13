#include <bits/stdc++.h>
using namespace std;

/*
1 1
2 x 2           
3 x x 3         
4 x x x 4       4 3 2 x x x 2 3 4
5 x x x x 5
6 x x x x x 6

5 4 3 2 1 6 1 2 3 4 5 6
*/

void solve() {
    int x;
    cin >> x;

    for (int i=x-1; i>0; i--) {
        cout << i << ' ';
    }
    cout << x << ' ';
    for (int i=1; i<x; i++) {
        cout << i << ' ';
    }
    cout << x << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
