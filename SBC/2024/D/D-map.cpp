#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9 + 7;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N; int M;
    cin >> N >> M;

    vector<pair<int, int>> m;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        m.push_back({ a, b });
    }

    map<ll, int> dp;
    dp.emplace(0, 1);

    map<ll, int>::iterator curr;
    while ((curr = dp.begin())->first < N) {
        for (auto [ a, b ] : m) {
            if ((curr->first + a) % ((ll)1 << b) == 0) {
                dp[curr->first + a] = (dp[curr->first + a] + curr->second) % MOD;
            }
        }
        dp.erase(curr);
    }

    cout << dp[N] << '\n';
}
