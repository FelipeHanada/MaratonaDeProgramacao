#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n, m;
    vector<vector<ll>> a, t;
    Fenwick(int n, int m) : n(n), m(m), a(n, vector<ll>(m, 0)), t(n, vector<ll>(m, 0)) { }
    void set(int x, int y, int v) {
        int delta = v - a[x][y];
        a[x][y] = v; 
        for (int i=x; i<n; i=i|(i+1)) {
            for (int j=y; j<m; j=j|(j+1)) {
                t[i][j] += delta;
            }
        }
    }
    ll get(int x, int y) {
        ll ans = 0;
        for (int i=x; i>=0; i=(i&(i+1))-1) {
            for (int j=y; j>=0; j=(j&(j+1))-1) {
                ans += t[i][j];
            }
        }
        return ans;
    }
    ll get(int x1, int y1, int x2, int y2) {
        tie(x1, x2) = make_tuple(min(x1, x2), max(x1, x2));
        tie(y1, y2) = make_tuple(min(y1, y2), max(y1, y2));
        return get(x2, y2) - get(x2, y1-1) - get(x1-1, y2) + get(x1-1, y1-1);
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        Fenwick ft(n+5, n+5);

        string op; cin >> op;
        while (op != "END") {
            if (op == "SET") {
                int x, y, v; cin >> x >> y >> v;
                ft.set(x, y, v);
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << ft.get(x1, y1, x2, y2) << '\n';
            }

            cin >> op;
        }
    }
}
