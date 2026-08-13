#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);



int main() { _
    ll tt; cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        vector<ll> childs(n, 0);
        vector<ll> p(n, -1);
        for (ll i=1; i<n; i++) {
            ll x; cin >> x; x--;
            p[i] = x;
            childs[x]++;
        }

        vector<ll> deg = childs;
        queue<ll> q;
        for (ll i=0; i<n; i++) if (!deg[i]) q.push(i);
        vector<ll> h1(n, 0), h2(n, 0);

        ll ans = 0;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            ans += h2[curr] + 1;

            if (p[curr] != -1) {
                if (h1[curr] + 1 >= h1[p[curr]]) {
                    h2[p[curr]] = h1[p[curr]];
                    h1[p[curr]] = h1[curr] + 1;
                } else if (h1[curr] + 1 > h2[p[curr]]) {
                    h2[p[curr]] = h1[curr] + 1;
                }

                if (!(--deg[p[curr]])) q.push(p[curr]);
            }
        }

        cout << ans << '\n';
    }
}

/*

*/