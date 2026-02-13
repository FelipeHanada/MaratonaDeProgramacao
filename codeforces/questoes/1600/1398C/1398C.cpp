#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;

    ll ans = 0;
    char c;
    deque<int> dp(9*n*2+1, 0); // the n first are negative, dp[n] is the zero
    for (int i=0; i<n; i++) {
        cin >> c;
        int curr = c - '0';

        dp[9*n]++; // start a new subarray

        // adds c to every subarray
        for (int i=0; i<curr; i++) {
            dp.pop_front();
            dp.push_back(0);
        }

        // everyone needs one more
        dp.pop_back();
        dp.push_front(0);

        ans += dp[9*n];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}
