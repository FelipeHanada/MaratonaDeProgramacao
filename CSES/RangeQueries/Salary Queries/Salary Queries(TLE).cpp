#include <bits/stdc++.h>
using namespace std;


struct SparseSegTree {
    SparseSegTree *left, *right;
    int lb, rb;
    int sum;
    SparseSegTree(int l, int r) {
        left = right = nullptr;
        lb = l; rb = r;
        sum = 0;
    }
    void push_down() {
        if (left) return;
        if (rb - lb == 1) return;
        int mid = (lb + rb) / 2;
        left = new SparseSegTree(lb, mid);
        right = new SparseSegTree(mid, rb);
    }
    void add(int i, int v) {
        sum += v;
        push_down();
        if (left) {
            if (i < left->rb) left->add(i, v);
            else right->add(i, v);
        }
    }
    int get(int l, int r) {
        if (lb >= l && rb <= r) return sum;
        if (max(l, lb) >= min(r, rb)) return 0;
        if (!left) return 0; // se não tem filhos, então sum = 0
        return left->get(l, r) + right->get(l, r);
    }
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