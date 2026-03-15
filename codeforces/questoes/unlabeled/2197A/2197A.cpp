#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        auto check = [&](int i) {
            int di = 0;
            for (int j = i; j; j/=10) {
                di += j % 10;
            }
            return n == i - di;
        };
        
        int ans = 0;
        for (int i=n; i<=n+83; i++) {
            ans += check(i);
        }

        cout << ans << '\n';
    }
}
