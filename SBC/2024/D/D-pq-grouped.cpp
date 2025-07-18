#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int MOD = 1e9 + 7;


int main() {
    ll n; int m;
    cin >> n >> m;

    vector<int> v[61];
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    
    map<ll, pair<ll, set<int>>> dp;
    dp[n].first = 1;
    for (int i=0; i<61; i++) {
        if (!v[i].empty()) {
            dp[(n / ((ll)1 << i)) * ((ll)1 << i)].second.emplace(i);
        }
    }

    map<ll, pair<ll, set<int>>>::iterator curr;
    while ((curr = (--dp.end()))->first > 0) {
        auto [ curr_n, x ] = *curr;

        for (int b : x.second) {
            for (int a : v[b]) {
                dp[curr_n - a].first = (dp[curr_n - a].first + dp[curr_n].first) % MOD;
            }

            dp[curr_n - ((ll) 1 << b)].second.emplace(b);
        }

        dp.erase(curr);
    }

    cout << dp[0].first << '\n';
}
