#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


struct SegTree {
    ll size;
    vector<pair<ll, ll>> tree;
    SegTree(ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, {INT32_MIN, -1});
    }
    void set(ll i, pair<ll, ll> v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void set(ll i, pair<ll, ll> v) { set(i, v, 0, 0, size); }
    pair<ll, ll> get(ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return {INT32_MIN, -1};
        ll mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    pair<ll, ll> get(ll l, ll r) { return get(l, r, 0, 0, size); }
};

int main() { _
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (ll i=0; i<n; i++) cin >> a[i];
        set<int> minloc;
        
        if (n == 1) minloc.insert(0);
        if (n > 1 && a[1] >= a[0]) minloc.insert(0);
        for (ll i=1; i<n-1; i++) {
            if (a[i-1] >= a[i] && a[i+1] >= a[i]) minloc.insert(i);
        }
        if (n > 1 && a[n-2] >= a[n-1]) minloc.insert(n-1);

        vector<int> ar(minloc.size());
        {
            ll i=0;
            for (auto pos : minloc) {
                ar[i] = pos;
                i++;
            }
        }

        vector<vector<ll>> sum(minloc.size(), vector<ll>(n));
        ll i=0;
        for (auto pos : minloc) {
            sum[i][pos] = h - a[pos];
            ll curr = a[pos];
            for (ll j=pos+1; j<n; j++) {
                curr = max(curr, a[j]);
                sum[i][j] = sum[i][j-1] + h - curr;
            }

            curr = a[pos];
            for (ll j=pos-1; j>=0; j--) {
                curr = max(curr, a[j]);
                sum[i][j] = sum[i][j+1] + h - curr;
            }

            i++;
        }

        SegTree segtree(n);
        for (ll i=0; i<n; i++) {
            segtree.set(i, {a[i], i});
        }

        ll ans = 0;
        for (int i=0; i<ar.size(); i++) {
            ans = max(ans, sum[i][0] + sum[i][n-1] - (h - a[ar[i]]));
        }

        for (ll i=0; i<ar.size(); i++) {
            for (ll j=i+1; j<ar.size(); j++) {
                ll curr = 0;

                curr = sum[i][0] + sum[j][n-1];

                auto g = segtree.get(ar[i]+1, ar[j]);
                auto [v, idx] = g;
                if (idx != -1) {
                    curr += sum[i][idx] + sum[j][idx];
                    curr -= h - a[ar[i]];
                    curr -= h - a[ar[j]];
                    curr -= h - a[idx];
                }

                ans = max(ans, curr);
            }
        }

        cout << ans << '\n';
    }
}