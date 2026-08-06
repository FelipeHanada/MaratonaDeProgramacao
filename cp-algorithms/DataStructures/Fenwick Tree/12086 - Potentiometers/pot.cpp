#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    vector<int> tree;
    Fenwick(int n) : tree(n, 0) { }
    int get(int r) {
        int ans = 0;
        while (r >= 0) {
            ans += tree[r];
            r = (r & (r + 1)) - 1;
        }
        return ans;
    }
    int get(int l, int r) { return get(r) - get(l - 1); }
    void add(int i, int v) {
        while (i < tree.size()) {
            tree[i] += v;
            i = i | (i + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    int n; cin >> n;
    while (n) {
        if (tt > 1) cout << '\n';
        cout << "Case " << tt++ << ":\n";

        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        Fenwick ft(n);
        for (int i=0; i<n; i++) ft.add(i, a[i]);

        string op; cin >> op;
        while (op != "END") {
            if (op == "M") {
                int x, y; cin >> x >> y; x--; y--;
                cout << ft.get(x, y) << '\n';
            } else {
                int x, r; cin >> x >> r; x--;
                int delta = r - a[x];
                a[x] = r;
                ft.add(x, delta);
            }

            cin >> op;
        }

        cin >> n;
    }
}