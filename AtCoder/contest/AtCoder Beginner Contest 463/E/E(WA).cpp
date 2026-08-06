#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
constexpr ll md = ll(1e9)+7;
inline ll add(ll a, ll b) { return ((a%md) + (b%md)) % md;}
inline ll sub(ll a, ll b) { return ((a%md) - (b%md) + md) % md;}
inline ll mult(ll a, ll b) { return ((ll)(a%md) * (b%md)) % md;}
ll binpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
inline ll inv(ll a) { return binpow(a, md-2); }


/*
da pra saber o menor valor de Xi + Xj + Y
para algum j em O(logn) usando segtrees
*/

struct SegTree {
    ll size;
    vector<ll> tree;
    SegTree(ll n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size << 1, INT64_MAX);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        ll mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = min(tree[2*x+1], tree[2*x+2]);
    }
    void set(ll i, ll v) { set(i, v, 0, 0, size); }
    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= r || rx <= l) return INT64_MAX;
        if (lx >= l && rx <= r) return tree[x];
        ll mid = (lx + rx) / 2;
        return min(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    ll get(ll l, ll r) { return get(l, r, 0, 0, size); }
};

signed main() { _
    ll n, m, Y;
    cin >> n >> m >> Y;
    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i=0; i<m; i++) {
        ll x, y, t; cin >> x >> y >> t;
        x--; y--;
        adj[x].push_back(make_pair(y, t));
        adj[y].push_back(make_pair(x, t));
    }
    vector<ll> X(n);
    for (ll i=0; i<n; i++) cin >> X[i];
    
    vector<ll> dist(n, INT64_MAX);
    priority_queue<pair<ll, ll>> pq;
    pq.push({ 0, 0 });
    SegTree st(n);
    dist[0] = 0; st.set(0, X[0]);
    for (ll i=1; i<n; i++) {
        ll d = X[0] + X[i] + Y;
        dist[i] = d; st.set(0, d + X[i]);
        pq.push({ -d, i });
    }
    while (!pq.empty()) {
        auto [minusd, curr] = pq.top(); pq.pop();
        ll mm = min(st.get(0, curr), st.get(curr+1, n));
        ll d = min(-minusd, mm == INT64_MAX ? INT64_MAX : mm + X[curr] + Y);
        if (d > dist[curr]) continue;
        dist[curr] = d;

        for (auto [ neighbor, w ] : adj[curr]) {
            ll d = min(dist[curr] + w, min(st.get(0, neighbor), st.get(neighbor+1, n)) + X[neighbor] + Y);
            if (d < dist[neighbor]) {
                dist[neighbor] = d; st.set(neighbor, d + X[neighbor]);
                pq.push({ -d, neighbor });
            }
        }
    }

    for (ll i=1; i<n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

/*
nunca vale a pena usar dois saltos no mesmo caminho
    (Xi + Xj + Y) + (...) + (Xa + Xb + Y)
    > Xi + Xb + Y

    levando isso em consideração, basta rodar dijkstra
        e melhorar os caminhos depois



*/
