#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, b;
        cin >> a >> b;

        if (a >= b) {
            cout << "Alice\n";
            continue;
        }

        ll delta = b - a;
        // find min x that solves the equation
        // x / (x + delta) = 2 / 3
        // 3x = 2x + 2delta
        // x = 2delta

        cout << ((a >= 2*delta) ? "Bob" : "Alice") << '\n';
    }
}