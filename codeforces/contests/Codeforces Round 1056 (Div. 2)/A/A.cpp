#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int losers = 0;
        int winners = n;
        int ans = 0;
        int matches;
         while (winners > 1 || losers > 1) {
            matches = losers / 2;
            losers -= matches;
            ans += matches;
            if (winners > 1) {
                matches = winners / 2;
                winners -= matches;
                ans += matches;
                losers += matches;
            }
        }

        cout << ans + 1 << '\n';
    }
}