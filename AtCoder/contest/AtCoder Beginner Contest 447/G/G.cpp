#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;


int main() { _
    int n;
    cin >> n;
    vector<int> k(n), a(n);
    for (int i=0; i<n; i++) cin >> k[i] >> a[i];

    vector<map<tuple<int,int,int>, int>> dp(7);
    vector<set<int>> scores(7);
    dp[0][{-1,-1,-1}] = 0;
    for (int i=0; i<n; i++) {
        for (int j=6; j>0; j--) {
            for (auto [last, score] : dp[j-1]) {
                auto [x, y, z] = last;
                if (k[i] != x && k[i] != y && (k[i] != z || j == 5)) {
                    
                    if (dp[j].count({ k[i], x, y })) {
                        if (score + a[i] > dp[j][{ k[i], x, y }]) {
                            scores[j].extract(dp[j][{ k[i], x, y }]);
                            dp[j].erase({ k[i], x, y });
                            dp[j][{ k[i], x, y }] = score + a[i];
                            scores[j].insert(dp[j][{ k[i], x, y }]);
                        }

                    } else {
                        dp[j][{ k[i], x, y }] = score + a[i];
                        scores[j].insert(dp[j][{ k[i], x, y }]);
                    }
                }
            }

            while (scores[j].size() > 500) scores[j].extract(*scores[j].begin());

            map<tuple<int,int,int>, int> next;
            for (auto [last, v] : dp[j]) {
                if (scores[j].count(v)) next[last] = v;
            }
            dp[j] = next;
        }
    }

    if (dp[6].empty()) {
        cout << "-1\n";
    } else {
        int ans = 0;
        for (auto [last, v] : dp[6]) {
            ans = max(ans, v);
        }

        cout << ans << '\n';
    }
}
