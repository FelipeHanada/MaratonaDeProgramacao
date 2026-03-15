#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int MAX = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<ll> tprimes;
    vector<bool> sieve(MAX+1, 0);
    for (ll i=2; i<=MAX; i++) {
        if (sieve[i]) continue;
        tprimes.insert(i*i);
        for (int j=2*i; j<=MAX; j+=i) sieve[j] = 1;
    }

    while (n--) {
        ll x;
        cin >> x;

        cout << (tprimes.count(x) ? "YES" : "NO") << '\n';
    }
}