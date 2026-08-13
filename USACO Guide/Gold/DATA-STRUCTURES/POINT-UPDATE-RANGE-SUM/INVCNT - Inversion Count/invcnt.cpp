#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Fenwick {
    int n;
    vector<ll> t;
    Fenwick(int n) : n(n), t(n, 0) { }
    void add(int i, int v) {
        for (; i<n; i=i|(i+1)) {
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
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        Fenwick ft(int(1e7+5));

        ll ans = 0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            ans += i - ft.get(x);
            ft.add(x, 1);
        }

        cout << ans << '\n';
    }
}
