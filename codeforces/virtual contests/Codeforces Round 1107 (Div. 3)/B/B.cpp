#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x; cin >> x;
        int y = 1;
        while (x) {
            x /= 10;
            y *= 10;
        }
        y++;
        cout << y << '\n';
    }
}