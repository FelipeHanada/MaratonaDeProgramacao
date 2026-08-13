#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2*x+1, lx, mid);
        } else {
            set(i, v, 2*x+2, mid, rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        // find position of the i-esimal 1 (it only works if it exists)
        if (rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;
        if (i < tree[2*x+1]) {
            return get(i, 2*x+1, lx, mid);
        } else {
            return get(i - tree[2*x+1], 2*x+2, mid, rx);
        }
    }
    int get(int i) { return get(i, 0, 0, size); }
};

int main() {
    int n;
    cin >> n;

    SegTree segtree(n);
    stack<int> inv;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        inv.push(x - 1);
        segtree.set(i, 1);
    }

    stack<int> ans;
    while (!inv.empty()) {
        int curr = inv.top(); inv.pop();
        int i = segtree.get(inv.size()-curr-1);
        ans.push(i+1);
        segtree.set(i, 0);
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
}
