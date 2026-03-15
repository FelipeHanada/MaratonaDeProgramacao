#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return ((ll)a * b) % md;
}

struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
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
        tree[x] = add(tree[2*x+1], tree[2*x+2]);
    };
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return add(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int lower=0; lower<n; lower++) {
        // the lower element in a[] is 'lower'
        SegTree dp(n);
        // dp[i] = number of arrays a that can be constructed
        // such that the last element is <= i

        dp.set(lower, 1);
        for (int i=1; i<m; i++) {
            for (int j=n-1; j>=0; j--) {
                dp.set(j, dp.get(0, j+1));
            }
        }

        a[lower] = dp.get(0, n);
    }

    for (int upper=0; upper<n; upper++) {
        // the upper element in a[] is 'upper'
        SegTree dp(n);
        // dp[i] = number of arrays a that can be constructed
        // such that the last element is >= i

        dp.set(upper, 1);
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                dp.set(j, dp.get(j, n));
            }
        }

        b[upper] = dp.get(0, n);
    }

    for (int i=1; i<n; i++) b[i] = add(b[i], b[i-1]);    

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = add(ans, mult(a[i], b[i]));
    }
    cout << ans << '\n';
}
