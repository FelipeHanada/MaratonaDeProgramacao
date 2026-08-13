#include <bits/stdc++.h>
using namespace std;



int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        if (x % y == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}