#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() { _
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<pair<ll,int>>> dp(k, vector<pair<ll,int>>(n+1));
    for (int i=0; i<k; i++) {
        dp[i][0] = {0, -1};
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            dp[j][i] = { INT64_MAX, -1 };
            for (int x=0; x<k; x++) {
                if (x == j) continue;

                dp[j][i] = min(dp[j][i], { dp[x][i-1].first + (s[i-1] - 'A' != j), x });
            }
        }
    }

    ll ans = INT64_MAX;
    int last = -1;
    for (int i=0; i<k; i++) {
        if (dp[i][n].first < ans) {
            ans = dp[i][n].first;
            last = i;
        }
    }
    cout << ans << '\n';
    stack<char> stk;
    for (int i=n; i>0; i--) {
        stk.push(last + 'A');
        last = dp[last][i].second;
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << '\n';
}
