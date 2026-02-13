#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

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
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] ^ tree[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return 0;
        int mid = (lx + rx) / 2;
        int ans = 0;
        if (i < mid) { // ta na esquerda, se perder soma
            if (tree[2*x+1] < tree[2*x+2]) ans += (rx - lx) / 2;
            ans += get(i, 2*x+1, lx, mid);
        } else {
            if (tree[2*x+1] >= tree[2*x+2]) ans += (rx - lx) / 2;
            ans += get(i, 2*x+2, mid, rx);
        }
        return ans;
    }
    int get(int i) { return get(i, 0, 0, size); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    n = 1<<n;
    
    vector<int> a(n);
    SegTree st(n);
    for (int i=0; i<(n); i++) {
        cin >> a[i];
        st.set(i, a[i]);
    }

    while (q--) {
        int b, c;
        cin >> b >> c;
        b--;
        st.set(b, c);
        cout << st.get(b) << '\n';
        st.set(b, a[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
