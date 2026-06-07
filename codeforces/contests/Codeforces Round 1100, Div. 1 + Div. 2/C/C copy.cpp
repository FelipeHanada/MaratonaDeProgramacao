#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<ll> b(n);
        b[0] = abs(a[0]);
        for (ll i=1; i<n; i++) b[i] = b[i-1] + abs(a[i]);

        vector<ll> suffix(n+1);
        suffix[n] = 0;
        for (ll i=n-1; i>=0; i--) {
            suffix[i] = suffix[i+1] + a[i];
        }

        ll ans = 0;
        for (ll i=0; i<n; i++) ans += a[i];

        ll curr = INT64_MIN;
        ll m = -1;
        for (ll i=1; i<n; i++) if (a[i] > 0) {
            ll cand = b[i-1] - a[i] + suffix[i+1];
            if (cand > curr) {
                curr = cand;
                m = i;
            }
        }

        if (ans >= curr) {
            cout << "0\n\n";
        } else {
            vector<ll> moves;
            ll mod = 1;
            for (ll i=m-1; i>=0; i--) {
                if (a[i] * mod > 0) {
                    mod *= -1;
                    moves.push_back(i);
                }
            }

            cout << moves.size() + 1 << '\n';
            for (ll x : moves) cout << x + 1 << ' ';
            cout << m + 1 << " \n";
        }
    }
}

/*
11
2 10 -11 -3 10 -15 -7 18 16 17 -9
*/
