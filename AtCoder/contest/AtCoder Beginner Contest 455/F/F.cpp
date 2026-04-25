#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
constexpr int md = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}


struct SegTree {
    int size;
    vector<int> tree;
    vector<int> lazytree;
    vector<bool> lazy;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
        lazytree.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }
    void push(int x, int l, int r) {
        if (!lazy[x] || r - l == 1) return;
        lazy[x] = 0;
        lazy[2*x+1] = 1;
        lazy[2*x+2] = 1;

        tree[x] = add(tree[x], mult(lazytree[x], r - l));
        lazytree[2*x+1] = add(lazytree[2*x+1], lazytree[x]);
        lazytree[2*x+2] = add(lazytree[2*x+2], lazytree[x]);
        lazytree[x] = 0;
    }
    void addrange(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= l && rx <= r) {
            lazytree[x] = add(lazytree[x], v);
            lazy[x] = 1;
            return;
        }
        if (lx >= r || rx <= l) return;
        int mid = (lx + rx) / 2;
        addrange(l, r, v, 2*x+1, lx, mid);
        addrange(l, r, v, 2*x+2, mid, rx);
    }
    void addrange(int l, int r, int v) { addrange(l, r, v, 0, 0, size); }
    int getrange(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) {
            push(x, lx, rx);
            return tree[x];
        }
        if (lx >= r || rx <= l) return 0;
        push(x, lx, rx);
        int mid = (lx + rx) / 2;
        return add(getrange(l, r, 2*x+1, lx, mid), getrange(l, r, 2*x+2, mid, rx));
    }
    int getrange(int l, int r) { return getrange(l, r, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return tree[x];
        push(x, lx, rx);
        int mid = (lx + rx) / 2;
        if (i < mid) return get(i, 2*x+1, lx, mid);
        else return get(i, 2*x+2, mid, rx);
    }
    int get(int i) { return get(i, 0, 0, size); }

    int ans(int l, int r) {
        // binary search for best division
        if (r - l <= 1) return 0;

        int i = l, j = r;
        // sum[l..i-1] <= sum[i..r]
        while (j - i > 1) {
            int mid = (i + j) / 2;
            if (getrange(l, mid) <= getrange(mid, r)) i = mid;
            else j = mid;
        }

        int left = getrange(l, i);
        int right = getrange(i, r);
        int ansleft = ans(l, i);
        int ansright = ans(i, r);

        return add(
            mult(left, right),
            add(ansleft, ansright)
        );
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SegTree segtree(n);
    while (q--) {
        int l, r, a;
        cin >> l >> r >> a;
        l--;
        segtree.addrange(l, r, a);

        for (int i=0; i<n; i++) cout << segtree.getrange(i, i+1) << ' ';
        cout << '\n';

        cout << segtree.ans(l, r) << '\n';
    }
}

/*
5 4
1 3 22
3 4 13
5 5 455
1 5 1000000000

0 0 0 0 0

22 22 22 0 0
-> 

*/