#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;


int main() {
    vector<ll> good;
    set<ll> seen;
    stack<ll> dfs;
    vector<pair<ll, ll>> pow2;
    vector<ll> pow10 = {1};
    for (ll i=1; i<=9; i++) pow10.push_back(pow10.back() * 10);

    for (ll i=1; i <= ll(1e9); i<<=1) {
        good.push_back(i);
        seen.insert(i);
        dfs.push(i);
        pow2.push_back({i, 1 + ll(log10(i))});
    }

    while (!dfs.empty()) {
        auto curr = dfs.top(); dfs.pop();
        for (auto [p2, offset] : pow2) {
            ll neighbor = curr * pow10[offset] + p2;
            if (neighbor > ll(1e9)) continue;
            if (seen.count(neighbor)) continue;
            seen.insert(neighbor);
            good.push_back(neighbor);
            dfs.push(neighbor);
        }
    }

    sort(good.begin(), good.end());

    ll n;
    cin >> n;
    cout << good[n-1] << '\n';
}
