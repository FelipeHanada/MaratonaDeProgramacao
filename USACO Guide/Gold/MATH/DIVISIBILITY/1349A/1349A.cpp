#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 200000;

ll binpow(ll a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main() {
    vector<int> sieve(N+1, 0);
    for (int i=2; i<=N; i++) if (!sieve[i]) {
        for (int j=i; j<=N; j+=i) if (!sieve[j]) {
            sieve[j] = i;
        }
    }

    int n; cin >> n;
    map<int, pair<int, int>> small;
    map<int, int> primes;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        map<int, int> curr;
        while (x > 1) {
            curr[sieve[x]]++;
            x /= sieve[x];
        }

        for (auto [ p, cnt ] : curr) {
            primes[p]++;
            if (!small.count(p)) {
                small[p] = { INT32_MAX, cnt };
            } else {
                if (cnt < small[p].second) {
                    small[p] = { small[p].second, cnt };
                } else if (cnt < small[p].first) {
                    small[p].first = cnt;
                }
            }
        }
    }

    ll ans = 1;
    for (auto [ p, cnt ] : small) {
        auto [ s, ss ] = cnt;

        if (n - primes[p] == 0) {
            ans *= binpow(p, s);
        } else if (n - primes[p] == 1) {
            // someone has p^0 in its factorization
            ans *= binpow(p, ss);
        }
    }

    cout << ans << '\n';
}
