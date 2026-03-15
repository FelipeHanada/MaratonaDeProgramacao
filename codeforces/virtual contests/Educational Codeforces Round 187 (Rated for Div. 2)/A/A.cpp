#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, d;
        cin >> n >> m >> d;
        int ans = 0;
        int curr = 0;
        while (n) {
            if (m > curr) {
                ans++;
                curr = d;
            } else {
                curr -= m;
            }
            n--;
        }

        cout << ans << '\n';
    }
}
