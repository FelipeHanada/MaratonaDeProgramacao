#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr ll MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    ll ans = 1;
    for (auto &[x, c] : m) {
        ans = (ans * (c+1) % MOD) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD; // excludes empty set

    cout << ans << '\n';
}