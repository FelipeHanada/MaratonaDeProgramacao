#include <bits/stdc++.h>
using namespace std;


#define ll long long

set<ll> primes;
void precompute() {
    ll acc = 2;
    primes.insert(2);
    for (int p = 3; acc < (ll)1e18 + 1; p += 2) {
        bool prime = true;
        for (int i=3; prime && i*i <= p; i+=2) {
            if (!(p % i)) prime = false;
        }
        if (prime) {
            primes.insert(p);
            acc *= p;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    ll ans = INT64_MAX;
    ll a;
    for (int i=0; i<n; i++) {
        cin >> a;
        for (auto p : primes) {
            if (a % p) {
                ans = min(ans, p);
                break;
            }
        }
    }

    if (ans == INT64_MAX) ans = -1;
    cout << ans << '\n';
}

int main() {
    int t;
    precompute();
    cin >> t;
    while (t--) {
        solve();
    }
}
