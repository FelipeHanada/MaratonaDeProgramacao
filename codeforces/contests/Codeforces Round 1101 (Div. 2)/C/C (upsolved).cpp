#include <bits/stdc++.h>
using namespace std;

/*
20 5 5
AEIEEEEIEAAEIEEEEIEA

AEIEEEEIEAAEIEEEEIEA

IEIEEEEIEEEEIEEEEIEE

IEIEEEEIEIEEIEEEEIEE

IEIEEEEIEIIEIEEEEIEE
^

IEIEEEEIEIIEIEEEEIEI
                   ^
5 12 => 17
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b; string s;
        cin >> n >> a >> b >> s;

        auto check = [&](int k) -> int {
            int empty = a, rem = 0;
            for (char c : s) {
                if (c == 'I' || (c == 'A' && k)) {
                    if (empty) {
                        empty--;
                        rem += b - 1;
                    }
                    if (c == 'A') k--;
                } else if (rem) {
                    rem--;
                }
            }

            return (a - empty) * b - rem;
        };

        if (check(0) > check(1)) {
            cout << check(0) << '\n';
            continue;
        }

        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid) < check(mid + 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << check(l + 1) << '\n';
    }
}
