#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
 4 0
 7 1
44 2
47 3 *
74 4
77 5  *
444
447
474
477
744
747
774
777


4:  1   2   4
7:  2   4   8

*/

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n;
    cin >> n;
    ll ans = 0;
    ll p = 1;
    while (n) {
        if (n % 10 == 4) {
            ans += p;
        } else {
            ans += p << 1;
        }
        n /= 10;
        p <<= 1;
    }

    cout << ans << '\n';
}