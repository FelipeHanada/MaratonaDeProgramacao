#include <bits/stdc++.h>
using namespace std;


/*
let a permutation P where P[i] = x
find(x) is always not UNDEFINED iff.
1) there is no P[j] > x with j < x  (eq. there is no bigger number on the left)
2) there is no P[j] < x with j > x  (eq. there is no smaller number on the right)


5
10100
-> 1 (2-5)
-> (1-2) 3 (4-5)

greedy strategy:
    1. fix all the 1's indices
    2. fill the rest satisfying the fixed indices and in inverse order
    3. check if it does satisfies the problem
*/


struct SegTree {
    int size;
    vector<int> tree_max;
    vector<int> tree_min;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree_max.assign(size*2, INT32_MIN);
        tree_min.assign(size*2, INT32_MAX);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree_max[x] = v;
            tree_min[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree_min[x] = min(tree_min[2*x+1], tree_min[2*x+2]);
        tree_max[x] = max(tree_max[2*x+1], tree_max[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get_min(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree_min[x];
        if (lx >= r || rx <= l) return INT32_MAX;
        int mid = (lx + rx) / 2;
        return min(get_min(l, r, 2*x+1, lx, mid), get_min(l, r, 2*x+2, mid, rx));
    }
    int get_min(int l, int r) { return get_min(l, r, 0, 0, size); } 
    int get_max(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree_max[x];
        if (lx >= r || rx <= l) return INT32_MIN;
        int mid = (lx + rx) / 2;
        return max(get_max(l, r, 2*x+1, lx, mid), get_max(l, r, 2*x+2, mid, rx));
    }
    int get_max(int l, int r) { return get_max(l, r, 0, 0, size); } 
};


void solve() {
    int n;
    cin >> n;
    set<int> fixed;
    vector<int> ans(n, -1);
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c == '1') {
            fixed.insert(i);
            ans[i] = i+1;
        }
    }
    fixed.insert(-1);
    fixed.insert(n);

    SegTree segtree(n);
    for (int x : fixed) {
        // fill left
        auto ub = upper_bound(fixed.begin(), fixed.end(), x);
        if (ub == fixed.end()) continue;
        int next = *ub;

        for (int i=1; x+i<next; i++) {
            ans[x+i] = next - i + 1;
            segtree.set(x+i, next - i + 1);
        }
    }

    // check if it is valid
    for (int i=0; i<n; i++) if (!fixed.count(i)) {
        if (!(segtree.get_max(0, i) > ans[i] || segtree.get_min(i+1, n) < ans[i])) {
            cout << "NO\n";
            return;            
        }
    }

    cout << "YES\n";
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
