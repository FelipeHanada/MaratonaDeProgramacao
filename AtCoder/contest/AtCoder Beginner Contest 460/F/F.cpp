#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> diam;
    vector<int> a, b;
    vector<int> color;
    function<int(int,int)> distance;
    SegTree(int n, function<int(int, int)> df) {
        size = 1;
        while (size < n) size *= 2;
        diam.assign(size * 2, INT32_MIN);
        a.assign(size * 2, -1);
        b.assign(size * 2, -1);
        color.assign(size, 0);
        distance = df;
    }
    void merge(int x, int lx, int rx) {
        vector<int> cand;
        if (a[2*x+1] != -1) cand.push_back(a[2*x+1]);
        if (b[2*x+1] != -1) cand.push_back(b[2*x+1]);
        if (a[2*x+2] != -1) cand.push_back(a[2*x+2]);
        if (b[2*x+2] != -1) cand.push_back(b[2*x+2]);
        if (cand.empty()) {
            a[x] = b[x] = -1;
            diam[x] = INT32_MIN;
        } else {
            diam[x] = INT32_MIN;
            for (int i=0; i<cand.size(); i++) {
                for (int j=i+1; j<cand.size(); j++) {
                    int d = distance(cand[i], cand[j]);
                    if (d > diam[x]) {
                        diam[x] = d;
                        a[x] = cand[i];
                        b[x] = cand[j];
                    }
                }
            }
        }
    }
    void flip(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            color[i] = 1 - color[i];
            if (color[i]) {
                a[x] = b[x] = i;
                diam[x] = 0;
            } else {
                a[x] = b[x] = -1;
                diam[x] = INT32_MIN;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) flip(i, 2*x+1, lx, mid);
        else flip(i, 2*x+2, mid, rx);   
        merge(x, lx, rx);
    }
    void flip(int i) { flip(i, 0, 0, size); }
    int get() {
        return diam[0];
    }
};

vector<vector<int>> adj;
vector<int> height;
vector<pair<int, int>> euler;
vector<int> f;
void dfs(int i, int p) {
    f[i] = euler.size();
    euler.push_back({ height[i], i });

    for (int j : adj[i]) if (j != p) {
        height[j] = height[i] + 1;
        dfs(j, i);
        euler.push_back({ height[i], i });
    }
}
vector<vector<pair<int,int>>> st;
int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    height.resize(n); height[0] = 0;
    f.resize(n);
    dfs(0, -1);

    st.push_back(euler);
    for (int k=1; (1<<k) <= euler.size(); k++) {
        st.push_back(vector<pair<int,int>>());
        for (int i=0; i + (1<<k) <= euler.size(); i++) {
            st[k].push_back(min(st[k-1][i], st[k-1][i+(1<<(k-1))]));
        }
    }

    auto min_st = [&](int l, int r) -> pair<int, int> {
        int k = flog2(r - l);
        return min(st[k][l], st[k][r - (1<<k)]);
    };

    auto lca = [&](int i, int j) -> int {
        int l = min(f[i], f[j]), r = max(f[i], f[j]);
        return min_st(l, r + 1).second;
    };

    auto distance = [&](int i, int j) -> int {
        return height[i] + height[j] - 2*height[lca(i, j)];
    };

    SegTree segtree(n, distance);
    for (int i=0; i<n; i++) segtree.flip(i);

    int q; cin >> q;
    while (q--) {
        int x; cin >> x; x--;
        segtree.flip(x);
        cout << segtree.get() << '\n';
    }
}
