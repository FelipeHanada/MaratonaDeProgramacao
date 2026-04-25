#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


ll lcm(ll a, ll b) {
    return (ll(a) * b) / __gcd(a, b);
}

/*
é sempre ótimo diminuir a[i]


temos que resolver quando não dá pra subtrair a[i], mas dá para aumentar

se não da pra subtrair a[i], então
min{gcd(a[i-1], a[i]), gcd(a[i], a[i+1])} = a[i]

WLOG. gcd(a[i-1], a[i]) = a[i]

seja k o novo valor de a[i], k deve satisfazer
    k > a[i]
    gcd(a[i-1], k) = a[i]
    gcd(k, a[i+1]) = gcd(a[i], a[i+1])

    dessa forma: k deve ser múltiplo de a[i]
        então, a partir de agora tomaremos k' como o fator ao qual a[i] é multiplicado
            (k = k' * a[i])
    
    k' deve ser coprimo com a[i-1]
    k' deve ser coprimo com a[i+1]

    é sempre ótimo que k' seja um primo
        (se fosse composto, poderíamos tomar qualquer primo que o compõe)
*/


int main() {
    vector<ll> primes;
    ll prod = 1;
    vector<bool> p(1e6, 1);
    for (ll i=2; i < p.size(); i++) {
        if (p[i]) {
            primes.push_back(i);
            prod = prod * i;
        }
        for (ll j=i; j< p.size(); j+=i) {
            p[j] = 0;
        }
    }

    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i=0; i<n; i++) cin >> a[i];
        for (ll i=0; i<n; i++) cin >> b[i];


        vector<bool> can(n, 1);
        ll ans = 0;
        if (__gcd(a[0], a[1]) < a[0]) {
            can[0] = 0;
            if (__gcd(a[0], a[1]) <= b[0]) {
                ans++;
                a[0] = __gcd(a[0], a[1]);
            }
        }

        if (__gcd(a[n-2], a[n-1]) <= min(a[n-1]-1, b[n-1])) {
            can[n-1] = 0;
            if (__gcd(a[n-2], a[n-1]) <= b[n-1]) {
                ans++;
                a[n-1] = __gcd(a[n-2], a[n-1]);
            }
        }

        for (ll i=1; i<n-1; i++) {
            ll x = lcm(__gcd(a[i-1], a[i]), __gcd(a[i], a[i+1]));
            if (x < a[i]) {
                can[i] = 0;
                if (x > b[i]) continue;
                ans++;
                a[i] = x;
            }
        }


        vector<ll> biggest(n, -1);

        if (can[0]) {
            auto ub = upper_bound(primes.begin(), primes.end(), b[0]/a[0]);
            while (ub != primes.begin()) {
                ll cand = *(--ub);
                if (__gcd(a[0] * cand, a[1]) == __gcd(a[0], a[1])) {
                    biggest[0] = distance(primes.begin(), ub);
                    break;
                }
            }
        }

        if (can[n-1]) {
            auto ub = upper_bound(primes.begin(), primes.end(), b[n-1]/a[n-1]);
            while (ub != primes.begin()) {
                ll cand = *(--ub);
                if (__gcd(a[n-1] * cand, a[n-2]) == __gcd(a[n-1], a[n-2])) {
                    biggest[n-1] = distance(primes.begin(), ub);
                    break;
                }
            }
        }

        for (ll i=1; i<n-1; i++) if (can[i]) {
            auto ub = upper_bound(primes.begin(), primes.end(), b[i]/a[i]);
            while (ub != primes.begin()) {
                ll cand = *(--ub);
                if (
                    __gcd(a[i] * cand, a[i-1]) == __gcd(a[i], a[i-1])
                    && __gcd(a[i] * cand, a[i+1]) == __gcd(a[i], a[i+1])
                ) {
                    biggest[i] = distance(primes.begin(), ub);
                    break;
                }
            }
        }

        vector<pair<int,int>> ord;
        for (int i=0; i<n; i++) if (biggest[i] != -1) {
            ord.push_back({biggest[i], i});
        }
        sort(ord.begin(), ord.end());

        for (auto [big, i] : ord) {
            if (i == 0) {
                for (int x=big; x>=0; x--) {
                    if (__gcd(a[0] * primes[x], a[1]) == __gcd(a[0], a[1])) {
                        ans++;
                        a[0] = a[0] * primes[x];
                        break;
                    }
                }
            } else if (i == n-1) {
                for (int x=big; x>=0; x--) {
                    if (__gcd(a[n-1] * primes[x], a[n-2]) == __gcd(a[n-1], a[n-2])) {
                        ans++;
                        a[n-1] = a[n-1] * primes[x];
                        break;
                    }
                }
            } else {
                for (int x=big; x>=0; x--) {
                    int cand = primes[x];
                    if (
                        __gcd(a[i] * cand, a[i-1]) == __gcd(a[i], a[i-1])
                        && __gcd(a[i] * cand, a[i+1]) == __gcd(a[i], a[i+1])
                    ) {
                        ans++;
                        a[i] = a[i] * cand;
                        break;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}
