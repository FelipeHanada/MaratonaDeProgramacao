#include <bits/stdc++.h>
using namespace std;

/*
se x = 0 e y = 0, então dá em 0 passos
se x != 0 e y = 0, então dá 1 em 1 passo
se x = y, então não dá
se x < y então dá em 2 passos
se x > y, então
    se tem um inteiro que x-k > y e k < y, então dá em 3 passos
caso contrário não dá
*/


void solve() {
    int x, y;
    cin >> x >> y;

    if (x == 0 && y == 0) {
        cout << "0\n";
    } else if (y == 0) {
        cout << "1\n";
    } else if (x == y) {
        cout << "-1\n";
    } else if (x < y) {
        cout << "2\n";
    } else if (x-1 > y && 1 < y) {
        cout << "3\n";
    } else {
        cout << "-1\n";
    }
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
