#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> mins;
    vector<int> counts;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        mins.assign(2*size, INT32_MAX);
        counts.assign(2*size, 1);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2*x+1, lx, mid);
        } else {
            set(i, v, 2*x+2, mid, rx);
        }
        mins[x] = min(mins[2*x+1], mins[2*x+2]);
        counts[x] = 0;
        if (mins[x] == mins[2*x+1]) counts[x] += counts[2*x+1];
        if (mins[x] == mins[2*x+2]) counts[x] += counts[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    pair<int, int> get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return make_pair(mins[x], counts[x]);
        if (lx >= r || rx <= l) return make_pair(INT32_MAX, 1);

        int mid = (lx + rx) / 2;
        pair<int, int> left, right, ans;
        left = get(l, r, 2*x+1, lx, mid);
        right = get(l, r, 2*x+2, mid, rx);
        ans = make_pair(min(left.first, right.first), 0);
        if (ans.first == left.first) ans.second += left.second;
        if (ans.first == right.first) ans.second += right.second;
        return ans;
    }
    pair<int, int> get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        segtree.set(i, x);
    }

    int a, b;
    pair<int, int> ans;
    while (m--) {
        cin >> x >> a >> b;
        if (x == 1) {
            segtree.set(a, b);
        } else {
            ans = segtree.get(a, b);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}
