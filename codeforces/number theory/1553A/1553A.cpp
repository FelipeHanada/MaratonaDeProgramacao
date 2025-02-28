#include <bits/stdc++.h>
using namespace std;

// S(x + 1) < S(x) if and only if x % 10 = 9
// there are 1 number like that ever 10 numbers

int solve(int n) {
    return n / 10 + ((n % 10 == 9) ? +1 : 0);
}

int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}