#include <bits/stdc++.h>
using namespace std;


int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;

        if (x & y == 0) {
            cout << x << ' ' << y << '\n';
            continue;
        }

        // we can treat cases
        array<int,3> ans = {INT32_MAX, -1, -1};

        { // I) p <= x && q <= y
            int remX = x, remY = y;
            int p = 0, q = 0;
            for (int i=31; i>=0; i--) {
                if (x & (1<<i)) {
                    p |= (1<<i);
                    remX &= ~(1<<i);
                } else if (y & (1<<i)) {
                    q |= (1<<i);
                    remY &= ~(1<<i);
                } else if (remX & ~((1<<i)-1)) {
                    p |= (1<<i);
                    remX &= ~(1<<i);
                } else if (remY & ~((1<<i)-1)) {
                    q |= (1<<i);
                    remY &= ~(1<<i);
                }
            }
            ans = min(ans, {x-p + y-q, p, q});
        }

        { // II) p >= x && q <= y
            int remX, remY;
            remY = y;
            int p = x, q = 0;
            for (int i=31; i>=0; i--) {
                if (x & (1<<i)) continue;
                if (y & (1<<i)) {
                    q |= (1<<i);
                    remY &= ~(1<<i);
                } else if (remY & ~((1<<i)-1)) {
                    q |= (1<<i);
                    remY &= ~(1<<i);
                }
            }
            ans = min(ans, {x-p + y-q, p, q});

            remX = x;
            p = 0, q = y;
            for (int i=31; i>=0; i--) {
                if (y & (1<<i)) continue;
                if (x & (1<<i)) {
                    p |= (1<<i);
                    remX &= ~(1<<i);
                } else if (remX & ~((1<<i)-1)) {
                    p |= (1<<i);
                    remX &= ~(1<<i);
                }
            }
            ans = min(ans, {x-p + y-q, p, q});
        }

        { // III) p >= x && q >= y
            int p = x, q = y&(~((1<<(flog2(x&y)+1))-1));
            for (int i=flog2(x&y)+1; i<31; i++) {
                if (!(x&(1<<i)) && !(y&(1<<i))) {
                    q |= (1<<i);
                    break;
                } else {
                    q &= ~(1<<i);
                }
            }
            ans = min(ans, {p-x + q-y, p, q});

            p = x&(~((1<<(flog2(x&y)+1))-1)), q = y;
            for (int i=flog2(x&y)+1; i<31; i++) {
                if (!(x&(1<<i)) && !(y&(1<<i))) {
                    p |= (1<<i);
                    break;
                } else {
                    p &= ~(1<<i);
                }
            }
            ans = min(ans, {p-x + q-y, p, q});
        }


        cout << ans[1] << ' ' << ans[2] << '\n';
    }
}