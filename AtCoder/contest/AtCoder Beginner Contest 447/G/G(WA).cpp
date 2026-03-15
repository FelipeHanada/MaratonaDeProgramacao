#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;


struct SegTree {
    int size;
    vector<int> tree;
    vector<stack<pair<int,int>>> leafs;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        leafs.assign(size, stack<pair<int, int>>());
        for (int i=0; i<size; i++) leafs[i].push({INT32_MIN, INT32_MIN});
        tree.assign(2*size, INT32_MIN);
    }
    void push(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            leafs[i].push({v, max(leafs[i].top().second, v)});
            tree[x] = leafs[i].top().second;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) push(i, v, 2*x+1, lx, mid);
        else push(i, v, 2*x+2, mid, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void push(int i, int v) { push(i, v, 0, 0, size); }
    void pop(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            leafs[i].pop();
            tree[x] = leafs[i].top().second;
            return;
        }
        int mid  = (lx + rx) / 2;
        if (i < mid) pop(i, 2*x+1, lx, mid);
        else pop(i, 2*x+2, mid, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void pop(int i) { pop(i, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT32_MIN;
        int mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() { _
    int n;
    cin >> n;
    vector<int> k(n), a(n);
    for (int i=0; i<n; i++) cin >> k[i] >> a[i];

    SegTree segtree(n+1);
    for (int i=n-1; i>=0; i--) {
        segtree.push(k[i], a[i]);
    }

    int ans = INT32_MIN;
    int i=0, j=0, p=0, q=0;
    while (i < n) {
        while (j < n && (j <= i || k[i] == k[j])) j++;
        while (p < n && (p <= j || k[i] == k[p] || k[j] == k[p])) p++;
        while (q < n && (q <= p || k[i] == k[q] || k[j] == k[q] || k[p] == k[q])) {
            segtree.pop(k[q]);
            q++;
        }
        if (i == j || j == p || p == q) break;

        int x = k[p], y = k[q];
        if (x > y) swap(x, y);
        ans = max(ans, segtree.get(0, x))
    }
}
