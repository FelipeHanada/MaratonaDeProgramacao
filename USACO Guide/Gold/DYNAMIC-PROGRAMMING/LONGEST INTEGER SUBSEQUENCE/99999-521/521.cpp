#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second

struct SegTree {
    int size;
    vector<int> max_tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        max_tree.assign(size * 2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            max_tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2*x+1, lx, mid);
        } else {
            set(i, v, 2*x+2, mid, rx);
        }
        max_tree[x] = max(max_tree[2*x+1], max_tree[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get_max(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return max_tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return max(get_max(l, r, 2*x+1, lx, mid), get_max(l, r, 2*x+2, mid, rx));
    }
    int get_max(int l, int r) { return get_max(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> points(n);
    set<int> ys;
    for (int i=0; i<n; i++) {
        cin >> points[i].f >> points[i].s;
        ys.insert(points[i].s);
    }

    vector<int> sorted(n);
    iota(sorted.begin(), sorted.end(), 0);
    sort(sorted.begin(), sorted.end(), [&](const int i, const int j) -> bool {
        return points[i].f < points[j].f || (points[i].f == points[j].f && points[i].s > points[j].s);
    });

    map<int, int> compressed;
    int at = 0;
    for (int y : ys) {
        if (!compressed.count(y)) compressed[y] = at++;
    }
    auto cmp = [&](int y) -> int { return compressed[y]; };

    vector<int> lis(n); // in sorted order
    SegTree segtree(compressed.size());
    for (int i=0; i<n; i++) {
        int max_prev = segtree.get_max(0, cmp(points[sorted[i]].s));
        segtree.set(cmp(points[sorted[i]].s), max_prev + 1);
        lis[i] = max_prev + 1;
    }

    vector<int> big(segtree.max_tree[0]+2, INT32_MIN);
    big[segtree.max_tree[0]+1] = INT32_MAX;
    map<int, vector<int>> ans;
    int count_lb = segtree.max_tree[0]; // size of the LIS
    for (int i=n-1; i>=0; i--) {
        if (lis[i] < count_lb || points[sorted[i]].s >= big[lis[i] + 1]) continue;
        big[lis[i]] = max(big[lis[i]], points[sorted[i]].s);
        ans[lis[i]].push_back(sorted[i]);
        if (lis[i] == count_lb) count_lb--;

    }

    set<int> A, B;
    for (auto [i, vertices] : ans) {
        A.insert(vertices.begin(), vertices.end());
        if (vertices.size() == 1) B.insert(vertices[0]);
    }

    cout << A.size() << ' ';
    for (int i : A) cout << i + 1 << ' ';
    cout << '\n';

    cout << B.size() << ' ';
    for (int i : B) cout << i + 1 << ' ';
    cout << '\n';
}
