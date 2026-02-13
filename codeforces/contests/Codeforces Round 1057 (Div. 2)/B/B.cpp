#include <bits/stdc++.h>
using namespace std;

#define ll long long


/*
a & b = x
b & c = y
a & c = z

(1) & (2) = a & b & b & c = a & b & c
(2) & (3) = a & a & b & c = a & b & c
(1) & (3) = a & b & c & c = a & b & c

iff. a & b & c = x & y = y & z = x & z
*/

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    cout << (((x&y) == (y&z) && (y&z) == (x&z)) ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
