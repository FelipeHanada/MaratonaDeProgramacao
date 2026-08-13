#include <bits/stdc++.h>
using namespace std;


int main() {
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;

    vector<vector<int>> dp(w+1, vector<int>(h+1, INT32_MIN));
    dp[0][0] = 0;
    for (int x=1; x<=w; x++) dp[x][0] = 0;
    for (int y=1; y<=h; y++) dp[0][y] = 0;

    for (int x=1; x<=w; x++) {
        for (int y=1; y<=h; y++) {
            dp[x][y] = max(dp[x-1][y], dp[x][y-1]);

            for (int i=0; i<n; i++) {
                if (x < a[i].first || y < a[i].second) continue;

                // places, and cuts horizontally
                int l = dp[x][y-a[i].second];
                int r = dp[x-a[i].first][a[i].second];
                if (min(l, r) > INT32_MIN)
                    dp[x][y] = max(dp[x][y], l + r + a[i].first * a[i].second);
                
                // places, and cuts vertically
                l = dp[x-a[i].first][y];
                r = dp[a[i].first][y-a[i].second];

                if (min(l, r) > INT32_MIN)
                    dp[x][y] = max(dp[x][y], l + r + a[i].first * a[i].second);
            }
        }
    }

    cout << w * h - dp[w][h] << '\n';
}