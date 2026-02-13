#include <bits/stdc++.h>
using namespace std;


struct MinSegTree {
    int size;
    vector<int> tree;
    MinSegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, INT32_MAX);
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
        tree[x] = min(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT32_MAX;
        int mid = (lx + rx) / 2;
        return min(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n, k;
    cin >> n >> k;

    MinSegTree og(n), stair(n);
    int x;

    for (int i=0; i<n; i++) {
        cin >> x;
        og.set(i, x);
        stair.set(i, x + i);
    }

    int best = 0;
    for (int i=0; i<n; i++) {
        int left = og.get(0, i-k+1), right = og.get(i+1, n);
        int in = stair.get(i-k+1, i+1) - i + k;
        best = max(best, min(min(left, right), in));
    }

    cout << best << '\n';
}
