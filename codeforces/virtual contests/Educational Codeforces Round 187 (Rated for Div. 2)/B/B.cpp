#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// F(645) = 15
// F(F(645)) = 6

// F(646) = 16
// F(F(645)) = 7

// 2374236843276813
// 2000200000200010

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        ll x;
        cin >> x;

        vector<int> digits;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int lead = digits.back();
        digits.pop_back();
        sort(digits.begin(), digits.end());

        int ans = 0;
        int curr, rem = lead;
        for (int d : digits) {
            if (rem + d < 10) rem += d;
            else ans++;
        }

        curr = 1; rem = 1;
        for (int d : digits) {
            if (rem + d < 10) rem += d;
            else curr++;
        }

        ans = min(ans, curr);

        cout << ans << '\n';
    }
}
