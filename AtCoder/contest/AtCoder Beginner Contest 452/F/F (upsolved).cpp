#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, 0);
    }
    void add(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) add(i, v, 2*x+1, lx, mid);
        else add(i, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void add(int i, int v) { add(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n; ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    auto f = [&](ll x) -> ll {
        SegTree st(n+5);
        ll ans = 0, curr = 0;
        int i=0, j=0;
        while (i < n) {
            while (j < n && curr + st.get(a[j], n+5) <= x) {
                curr += st.get(a[j], n+5);
                st.add(a[j], 1);
                j++;
            }

            ans += j - i;
            curr -= st.get(0, a[i]);
            st.add(a[i], -1);
            i++;
        }
        return ans;
    };


    cout << f(k) - (k ? f(k-1) : 0) << '\n';
}