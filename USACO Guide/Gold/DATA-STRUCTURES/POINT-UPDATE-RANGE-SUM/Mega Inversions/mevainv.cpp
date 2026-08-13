#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Fenwick {
    int n;
    vector<ll> t;
    Fenwick(int n) : n(n), t(n, 0) { }
    void add(int i, int v) {
        for (; i < n; i=i|(i+1)) {
            t[i] += v;
        }
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r=(r&(r+1))-1) {
            ans += t[r];
        }
        return ans;
    }
    ll get(int l, int r) {
        return get(r) - get(l-1);
    }
};

constexpr int N = int(1e5+5);

int main() {
    int n; cin >> n;
    Fenwick a(N), b(N);

    ll ans = 0;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        ans += b.get(x+1, N-1);
        b.add(x, a.get(x+1, N-1));
        a.add(x, 1);
    }

    cout << ans << '\n';
}
