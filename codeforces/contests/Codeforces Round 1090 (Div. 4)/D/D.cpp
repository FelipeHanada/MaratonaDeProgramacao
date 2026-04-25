#include <bits/stdc++.h>
using namespace std;

#define _f first
#define _s second
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    vector<ll> primes;
    vector<bool> sieve(ll(1e6), 0);
    for (ll i=2; i<ll(1e6); i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (ll j=i*2; j<ll(1e6); j+=i) sieve[j] = 1;
        }
    }

    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> ans;

        ll p = 0;
        while (ans.size() < n) {
            ll j = primes[p] * primes[p];
            if (p > 0) {
                ans.push_back(j * primes[p-1]);
                j *= primes[p];
            }

            while (ans.size() < n && j < ll(1e9)) {
                ans.push_back(j);
                j *= primes[p];
            }
            p++;
        }

        for (ll x : ans) {
            cout << x << ' ';
        }
        cout << '\n';

        // cout << '\n';
        // for (int i=0; i<n-1; i++) cout << __gcd(ans[i], ans[i+1]) << ' ';
        // cout << '\n';
    }
}
