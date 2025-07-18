#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int MOD = 1e9 + 7;


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v[61];
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    
    map<ll, int> dp;
    dp[0] = 1;

    set<pair<ll, int>> pq;  // using as a priority queue { n, b }
    for (int i=0; i<61; i++) {
        if (!v[i].empty())
            pq.emplace((pair<ll, int>){ 0, i });
    }

    while (pq.begin()->first < n) {
        auto [ curr_n, b ] = *(pq.begin()); pq.erase(pq.begin());

        while (dp.begin()->first < curr_n)
            dp.erase(dp.begin());

        for (auto a : v[b]) {
            dp[curr_n + a] = (dp[curr_n + a] + dp[curr_n]) % MOD;
        }

        curr_n += (ll) 1 << b;
        if (curr_n <= n)
            pq.emplace((pair<ll, int>){ curr_n, b });
    }

    cout << dp[n] << '\n';
}