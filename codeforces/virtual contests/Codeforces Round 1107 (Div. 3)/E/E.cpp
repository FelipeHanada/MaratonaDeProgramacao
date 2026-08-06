#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<vector<ll>> adj;
ll n;
vector<ll> sizes;
vector<ll> depth;
ll ans;
vector<ll> a;
void dfs(ll i, ll p) {
    sizes[i] = 1;
    for (ll j : adj[i]) if (j != p) {
        depth[j] = depth[i] + 1;
        dfs(j, i);
        sizes[i] += sizes[j];
    }
    
    ll x = sqrt(a[i]);
    if (x*x != a[i] && (x-1)*(x-1) != a[i] && (x+1)*(x+1) != a[i]) return;

    // se i é o pivô
    vector<ll> partes = { n - sizes[i] };
    for (ll j : adj[i]) if (j != p) partes.push_back(sizes[j]);
    // caso 1: i ta na tripla, então precisamos de 2 vértices em partes diferentes
    ll ans1 = 0;
    for (ll j : adj[i]) if (j != p) {
        ans1 += sizes[j] * (sizes[i] - 1 - sizes[j]);
    }
    ans1 /= 2;
    for (ll j : adj[i]) if (j != p) {
        ans1 += partes[0] * sizes[j];
    }


    // caso 2: i não ta na tripla, então precisamos de 3 vértices em partes diferentes
    ll ans2 = 0;
    // quantidade de triplas
    // - quantidade de triplas com 2 de um e 1 do outro
    // - quantidade de triplas só com 1

    ans2 += (n-1)*(n-2)*(n-3)/6;
    for (ll sizej : partes) {
        ans2 -= (sizej*(sizej-1))/2 * (n-1-sizej);
        ans2 -= sizej * (sizej-1) * (sizej-2) / 6;
    }
    ans += ans1 + ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        a.resize(n);
        for (ll i=0; i<n; i++) cin >> a[i];

        adj.clear();
        adj.resize(n);
        for (ll i=0; i<n-1; i++) {
            ll x, y; cin >> x >> y; x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        depth.resize(n); depth[0] = 0;
        ans = 0;
        sizes.resize(n);
        dfs(0, -1);

        cout << ans << '\n';
    } 
}


/*
case 1)
   u
   |
  ...
 /   \
 v   w

p(u, v) * p(v, w) * p(w, u) =
    [p(u, lca(v, w)) * p(lca(v, w), v)]
        * [p(v, lca(v, w)) * p(lca(v, w), w)]
        * [p(w, lca(v, w)) * p(lca(v, w), u)]
    = p(v, lca(v, w))^2 * p(lca(v, w), w)^2 * p(u, lca(v, w))^2

case 2)
  u -> v -> w

  sempre é um quadrado perfeito, porque p(w, u) = p(u, v) * p(v, w)
logo, 
    p(u, v) * p(v, w) * p(w, u) = (p(u, v) * p(v, w))^2


*/