#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define f first
#define s second
using ll = long long;


struct SegTree {
    ll size;
    vector<ll> tree;
    SegTree(ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, 0);
    }
    void add(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] += v;
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid) add(i, v, 2*x+1, lx, mid);
        else add(i, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void add(ll i, ll v) { add(i, v, 0, 0, size); }
    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        ll mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    ll get(ll l, ll r) { return get(l, r, 0, 0, size); }
};

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i=0; i<n; i++) cin >> a[i];

    ll curr = 0;
    ll i=0, j = 0;
    SegTree st(n+5);
    ll ans = 0;
    ll last_unchanged = 0;
    while (i < n) {
        while (j < n && curr + st.get(a[j]+1, n+1) <= k) {
            st.add(a[j], 1);
            ll delta = st.get(a[j]+1, n+1);
            if (delta) {
                last_unchanged = 0;
                curr += delta;
            }
            j++;

            if (curr == k) ans++;
            if (curr == k) last_unchanged++;
        }

        st.add(a[i], -1);
        ll delta = st.get(0, a[i]);
        curr -= delta;
        if (delta) {
            last_unchanged = 0;
            if (curr == k) ans++;
            if (curr == k) last_unchanged++;
        } else if (curr == k) {
            ans += last_unchanged;
        }
        i++;
    }

    cout << ans << '\n';
}
