#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> lis;
    vector<int> count;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lis.assign(size*2, 0);
        count.assign(size*2, 1);
    }
    void set(int i, int v, int c, int x, int lx, int rx) {
        if (rx - lx == 1) {
            lis[x] = v;
            count[x] = c;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, c, 2*x+1, lx, mid);
        } else {
            set(i, v, c, 2*x+2, mid, rx);
        }
        lis[x] = max(lis[2*x+1], lis[2*x+2]);
        count[x] = 0;
        if (lis[2*x+1] >= lis[2*x+2])
            count[x] += count[2*x+1];
        if (lis[2*x+2] >= lis[2*x+1])
            count[x] += count[2*x+2];
    }
    void set(int i, int v, int c) { set(i, v, c, 0, 0, size); }
    pair<int, int> get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return make_pair(lis[x], count[x]);
        if (lx >= r || rx <= l) return make_pair(0, 0);
        int mid = (lx + rx) / 2;
        pair<int, int> left = get(l, r, 2*x+1, lx, mid),
                       right = get(l, r, 2*x+2, mid, rx);
        pair<int, int> ans = make_pair(max(left.first, right.first), 0);
        if (left.first == ans.first)
            ans.second += left.second;
        if (right.first == ans.first)
            ans.second += right.second;
        return ans;
    }
    pair<int, int> get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    int big = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        big = max(big, v[i]);
    }

    SegTree segtree(big+1);
    for (int x : v) {
        auto [lis, count] = segtree.get(0, x);

        if (lis+1 == segtree.lis[segtree.size+x-1]) {
            count += segtree.count[segtree.size+x-1];
        }

        segtree.set(x, lis+1, count);
    }

    cout << segtree.lis[0] << ' ' << segtree.count[0] << '\n';
}
