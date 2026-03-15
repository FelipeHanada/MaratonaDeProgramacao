#include <bits/stdc++.h>
using namespace std;



using ll = long long;
#define _1 first
#define _2 second


int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;

    while (tt--) {
        ll n;
        cin >> n;
        ll ans = 1;

        for (int d : {2, 3, 5}) {
            if (n % d == 0) ans *= d;
            while (n % d == 0) n /= d;
        }
        static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
        int i = 0;
        for (long long d = 7; d * d <= n; d += increments[i++]) {
            if (n % d == 0) ans *= d;
            while (n % d == 0) n /= d;
            if (i == 8) i = 0;
        }
        if (n > 1) ans *= n;

        cout << ans << '\n';
    }
}
