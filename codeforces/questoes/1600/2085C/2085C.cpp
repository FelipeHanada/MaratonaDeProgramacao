#include <bits/stdc++.h>
using namespace std;

/*

0101
1001
   1

0110
1010
  11

1000
1100
  11

1000
1100
 111

10000
10100
  111

01100
10000

1111
1110

10000
01111
   1

we need to find k such that
(x + k) & (y + k) = 0

*/

#define ll long long

int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x == y) {
            cout << "-1\n";
            continue;
        }

        ll ans = 0;
        for (int i=0; i < max(flog2(x), flog2(y)); i++) {
            if (x & y & (1<<i)) {
                ans += (1<<i);
                x += (1<<i);
                y += (1<<i);
            }
        }

        if (__builtin_clz(x) == __builtin_clz(y)) {
            int i = flog2(x);
            for (; i>=0 && !((x & (1<<i)) ^ (y & (1<<i))); i--) {
                if (!((x & (1<<i)) | (y & (1<<i)))) {
                    ans += (1<<i);
                }
            }
            ans += (1<<i);
        }

        cout << ans << '\n';
    }
}