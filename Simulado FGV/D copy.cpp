#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        int c, s, r;
        cin >> c >> r >> s;

        int total = c + r;
        int q = (total + s - 1) / s;
        int qr = (r + s - 1) / s;
        int qs = q - qr;

        int boas = max(0, q - r);
        cout << qs << ' ' << boas << '\n';
    }
}