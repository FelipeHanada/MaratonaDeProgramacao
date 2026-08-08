#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ll n, m, q; cin >> n >> m >> q;

    map<ll, vector<ll>> groups;
    {
        map<ll, ll> cnt;
        for (ll i=0; i<n; i++) {
            ll x; cin >> x;
            cnt[x]++;
        }

        for (ll i=1; i<=m; i++) {
            groups[cnt[i]].push_back(i);
        }
    }

    vector<ll> ans(q);
    vector<pair<ll, ll>> query(q);
    for (ll i=0; i<q; i++) {
        cin >> query[i].first;
        query[i].first -= n;
        query[i].second = i;
    }
    sort(query.begin(), query.end());

    ordered_set s;
    ll curr;
    {
        auto &[ k, g ] = *groups.begin();
        for (ll x : g) s.insert(x);
        curr = k;
        groups.erase(groups.begin());
    }

    ll l = 0;
    ll last = 0;
    for (auto [ k, id ] : query) {
        tie(k, last) = make_tuple(k - last, k);

        if (l + k > s.size()) {
            k -= s.size() - l;
            l = 0;
            curr++;
            if (groups.count(curr)) {
                auto &[ k, g ] = *groups.begin();
                for (ll x : g) s.insert(x);
                groups.erase(groups.begin());
            }
        }

        while (k > s.size()) {
            ll lim = INT64_MAX;
            if (!groups.empty()) {
                auto &[ k, g ] = *groups.begin();
                lim = k;
            }

            ll steps = min(lim - curr, (k-1) / ll(s.size()));
            k -= steps * s.size();
            curr += steps;
            if (groups.count(curr)) {
                auto &[ k, g ] = *groups.begin();
                for (ll x : g) s.insert(x);
                groups.erase(groups.begin());
            }
        }

        ans[id] = *s.find_by_order(l + k - 1);
        l += k;
    }

    for (ll x : ans) cout << x << '\n';
}
