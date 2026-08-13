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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n, -1);
    vector<int> height(n, -1);
    {
        queue<array<int,3>> q; q.push({ 0, 0, 0 });
        while (!q.empty()) {
            auto [ i, p, h ] = q.front(); q.pop();
            parent[i] = p;
            height[i] = h;
            for (int j : adj[i]) if (j != p) {
                q.push({ j, i, h + 1 });
            }
        }
    }

    vector<vector<int>> up;
    up.push_back(parent);
    for (int i=1; i*i <= n; i++) {
        up.push_back(vector<int>(n));

        for (int j=0; j<n; j++) {
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    map<pair<int, int>, int> memo;
    auto distance = [&](int i, int j) -> int {
        if (height[i] < height[j]) swap(i, j);
        if (memo.count({i, j})) return memo[{i, j}];

        int ii = i, jj = j;
        for (int k=up.size()-1; k>=0 && height[ii] > height[jj]; k--) {
            if (height[up[k][ii]] >= height[jj]) {
                ii = up[k][ii];
            }
        }

        int lca;
        if (ii == jj) lca = j;
        else {
            for (int k=up.size()-1; k>=0 && parent[ii] != parent[jj]; k--) {
                if (up[k][ii] != up[k][jj]) {
                    ii = up[k][ii];
                    jj = up[k][jj];
                }
            }
            lca = up[0][ii];
        }

        return memo[{i, j}] = height[i] + height[j] - 2*height[lca];
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
