#include <bits/stdc++.h>
using namespace std;


using ll = long long;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1 is not prime, but it is easier this way
    // vector<ll> primes = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};
    vector<ll> primes = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i=0; i<n; i++) cin >> a[i];
        for (ll i=0; i<n; i++) cin >> b[i];
        
        ll ans = 0;
        vector<bool> can_change(n, 1);
        for (ll i=0; i<n; i++) {
            ll small = 1;

            if (i < n - 1) small = lcm(small, __gcd(a[i], a[i+1]));
            if (i > 0) small = lcm(small, __gcd(a[i-1], a[i]));

            if (small < a[i]) {
                if (small <= b[i]) {
                    ans++;
                    a[i] = small;
                }
                can_change[i] = 0;
            }
        }

        vector<ll> dp(primes.size(), 0), next(primes.size());
        bool skip = 0;
        for (ll i=0; i<n; i++) {
            // 1 means unchanged

            if (can_change[i]) {
                next[0] = 0;
                for (ll j=0; j<primes.size(); j++) next[0] = max(next[0], dp[j]);
    
                for (ll j=1; j<primes.size(); j++) {
                    next[j] = 0;
    
                    if (a[i] * primes[j] > b[i]) continue;
                    if (i < n-1 && __gcd(a[i] * primes[j], a[i+1]) != __gcd(a[i], a[i+1])) continue;
    
                    for (ll k=0; k<primes.size(); k++) {
                        if (i > 0 && __gcd(a[i-1] * primes[k], a[i] * primes[j]) != __gcd(a[i-1], a[i])) continue;
                        next[j] = max(next[j], dp[k] + 1);
                    }
                }

                skip = 0;
            } else {
                if (skip) continue;
                ll best = 0;
                for (int i=0; i<dp.size(); i++) best = max(best, dp[i]);
                for (int i=0; i<dp.size(); i++) next[i] = best;
                skip = 1;
            }

            swap(dp, next);
        }

        ll best = 0;
        for (ll i=0; i<dp.size(); i++) best = max(best, dp[i]);


        cout << ans + best << '\n';
    }
}