#include <bits/stdc++.h>
using namespace std;


using ull = unsigned long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        ull n, x;
        cin >> n >> x;

        bool ok = 1;
        for (int i=0; ok && i<63; i++) {
            if ((n&(1LL<<i)) < (x&(1LL<<i))) ok = 0;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        int diff = -1;
        for (int i=62; ok && i>=0; i--) {
            if ((n&(1LL<<i)) && !(x&(1LL<<i))) {
                if (i < 62 && (x&(1LL<<(i+1)))) ok = 0;
                
                if (diff == -1) diff = i;
            }

            if (diff != -1 && (x&(1LL<<i))) ok = 0;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        if (diff == -1) {
            cout << n << '\n';
        } else {
            ull ans = n | (1LL<<(diff+1));
            ans &= ~((1LL<<(diff+1))-1);
            cout << ans << '\n';
        }
    }
}
