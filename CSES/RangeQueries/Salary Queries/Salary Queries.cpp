#include <bits/stdc++.h>
using namespace std;

struct SparseSegTreeNode {
    int lb, rb;
    int sum = 0;
    int l = -1, r = -1;
};

struct SparseSegTree {
    vector<SparseSegTreeNode> tree;
    SparseSegTree(int l, int r) {
        tree.push_back({ l, r });
    }
    void push_down(int x) {
        if (tree[x].l != -1) return;
        if (tree[x].rb - tree[x].lb == 1) return;
        int mid = tree[x].lb + (tree[x].rb - tree[x].lb) / 2;
        tree[x].l = tree.size();
        tree.push_back({ tree[x].lb, mid });
        tree[x].r = tree.size();
        tree.push_back({ mid, tree[x].rb });
    }
    void add(int x, int i, int v) {
        tree[x].sum += v;
        push_down(x);
        if (tree[x].l != -1) {
            if (i < tree[tree[x].l].rb) add(tree[x].l, i, v);
            else add(tree[x].r, i, v);
        }
    }
    void add(int i, int v) { add(0, i, v); }
    int get(int x, int l, int r) {
        if (tree[x].lb >= r || tree[x].rb <= l) return 0;
        if (tree[x].lb >= l && tree[x].rb <= r) return tree[x].sum;
        if (tree[x].l == -1) return 0;
        return get(tree[x].l, l, r) + get(tree[x].r, l, r);
    }
    int get(int l, int r) { return get(0, l, r); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    SparseSegTree st(0, int(1e9)+1);
    for (int i=0; i<n; i++) st.add(a[i], 1);

    while (q--) {
        char op; cin >> op;

        if (op == '!') {
            int k, x; cin >> k >> x; k--;
            st.add(a[k], -1);
            a[k] = x;
            st.add(a[k], 1);
        } else {
            int a, b; cin >> a >> b; b++;
            cout << st.get(a, b) << '\n';
        }
    }
}