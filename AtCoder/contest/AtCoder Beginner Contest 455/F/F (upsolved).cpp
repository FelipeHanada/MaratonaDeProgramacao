#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int md = 998244353;
constexpr int inv2 = (998244353+1)/2;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}

struct SegTree {
    int size;
    vector<int> lazy;
    vector<int> sum;
    vector<int> sum2;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.assign(size*2, 0);
        sum.assign(size*2, 0);
        sum2.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!lazy[x]) return;

        sum2[x] = add(
            add(sum2[x], mult(rx - lx, mult(lazy[x], lazy[x]))),
            mult(2, mult(sum[x], lazy[x]))
        );
        sum[x] = add(sum[x], mult(lazy[x], rx - lx));

        if (rx - lx > 1) {
            lazy[2*x+1] = add(lazy[2*x+1], lazy[x]);
            lazy[2*x+2] = add(lazy[2*x+2], lazy[x]);
        }
        lazy[x] = 0;
    }
    void addrange(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = add(lazy[x], v);
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        addrange(l, r, v, 2*x+1, lx, mid);
        addrange(l, r, v, 2*x+2, mid, rx);
        sum[x] = add(sum[2*x+1], sum[2*x+2]);
        sum2[x] = add(sum2[2*x+1], sum2[2*x+2]);
    }
    void addrange(int l, int r, int v) { addrange(l, r, v, 0, 0, size); }
    int get_sum(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= l && rx <= r) return sum[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return add(get_sum(l, r, 2*x+1, lx, mid), get_sum(l, r, 2*x+2, mid, rx));
    }
    int get_sum(int l, int r) { return get_sum(l, r, 0, 0, size); }
    int get_sum2(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= l && rx <= r) return sum2[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return add(get_sum2(l, r, 2*x+1, lx, mid), get_sum2(l, r, 2*x+2, mid, rx));
    }
    int get_sum2(int l, int r) { return get_sum2(l, r, 0, 0, size); }
};

int main() {
    int n, q;
    cin >> n >> q;
    SegTree segtree(n+5);
    while (q--) {
        int l, r, a;
        cin >> l >> r >> a;
        l--;
        segtree.addrange(l, r, a);
        int sum = segtree.get_sum(l, r);
        int sum2 = segtree.get_sum2(l, r);
        cout << mult(sub(mult(sum, sum), sum2), inv2) << '\n';
    }
}


/*
independently on how the merge is being done
the cost is the same

proof.
its sufficient to show that the merging operation is associative
a merge (b merge c) results in a slime a+b+c with cost ab + bc + ac
(a merge b) merge c results in a slime a+b+c with cost ab + bc + ac

furthermore, the cost is the sum of the product of every distinct pair
this can be calculated as:
    (the square of the sum - the sum of each square) / 2

we can compute the values of the array at any moment
    by maintaining a Lazy Segment Tree that
    supports range query + range update

leading to a solution with complexity: O(QlogN)
*/
