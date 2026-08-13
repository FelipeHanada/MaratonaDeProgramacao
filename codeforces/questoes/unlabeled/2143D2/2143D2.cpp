#include <bits/stdc++.h>
using namespace std;

constexpr int md = int(1e9) + 7;
inline int add_md(int a, int b) { return ((a%md) + (b%md)) % md; }

struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size*2, 0);
    }
    void add(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = add_md(tree[x], v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) add(i, v, 2*x+1, lx, mid);
        else add(i, v, 2*x+2, mid, rx);
        tree[x] = add_md(tree[2*x+1], tree[2*x+2]);
    }
    void add(int i, int v) { add(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return add_md(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<SegTree> dp1(n+1, SegTree(n+1));
        vector<SegTree> dp2(n+1, SegTree(n+1));
        dp1[0].add(0, 1); dp2[0].add(0, 1);
        for (int i=0; i<n; i++) {
            // when placing a[i]
            // there is 3 cases
            // 1. a[i] >= x,                then a[i] is the new x
            // 2. a[i] < x and a[i] >= y,   then a[i] is the new y 
            // 3. a[i] < y                  does not count, since the subseq. would be invalid

            // 1. dp[a[i]][y] = sum of dp[0..a[i]][y]
            // 2. dp[x][a[i]] = sum of dp[x][0..a[i]]
            vector<int> ys(n+1), xs(n+1);
            for (int y=0; y<=n; y++) ys[y] = dp2[y].get(0, a[i]+1);
            for (int x = a[i] + 1; x <= n; x++) xs[x] = dp1[x].get(0, a[i]+1);
            
            for (int y=0; y<=n; y++) {
                dp1[a[i]].add(y, ys[y]);
                dp2[y].add(a[i], ys[y]);
            }

            for (int x = a[i] + 1; x <= n; x++) {
                dp1[x].add(a[i], xs[x]);
                dp2[a[i]].add(x, xs[x]);
            }
        }

        int ans = 0;
        for (int i=0; i<=n; i++) ans = add_md(ans, dp1[i].get(0, n+1));

        cout << ans << '\n';
    }
}

/*
uma subseq. é boa se não tem i < j < k t.q. a[i] > a[j] > a[k]

seja dp[x][y] = quantidade de subseq. onde o maior valor é x
                e o maior valor que tem um valor maior atrás é y
*/
