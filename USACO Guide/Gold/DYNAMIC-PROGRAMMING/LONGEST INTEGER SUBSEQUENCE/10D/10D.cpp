#include <bits/stdc++.h>
using namespace std;


struct MaxSegTree {
    int size;
    vector<pair<int, int>> tree;
    MaxSegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, make_pair(0, 0));
    }
    void set(int i, pair<int, int> v, int x, int lx, int rx) {
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
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, pair<int, int> v) { set(i, v, 0, 0, size); }
    pair<int, int> get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return make_pair(0, 0);
        int mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    pair<int, int> get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    set<int> values;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        values.insert(a[i]);
    }

    cin >> m;
    vector<int> b(m);
    for (int i=0; i<m; i++) {
        cin >> b[i];
        values.insert(b[i]);
    }

    map<int, int> comp; // using compression
    int at = 0;
    for (auto x : values) {
        comp[x] = at++;
    }
    
    vector<vector<pair<int, int>>> p(m, vector<pair<int, int>>(n, make_pair(-1, -1)));
    vector<MaxSegTree> segs(m, MaxSegTree(1001));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i] != b[j]) continue;
            pair<int, int> max_prev = make_pair(0, 0);
            int max_prev_k = -1;
            for (int k=0; k<j; k++) {
                auto curr = segs[k].get(0, comp[a[i]]);
                if (curr > max_prev) {
                    max_prev = curr;
                    max_prev_k = k;
                }
            }

            if (max_prev_k >= 0)
                p[j][i] = make_pair(max_prev_k, max_prev.second);

            segs[j].set(comp[a[i]], make_pair(max_prev.first + 1, i));
        }
    }

    pair<int, int> lis = make_pair(0, 0);
    int max_k = -1;
    for (int k=0; k<m; k++) {
        pair<int, int> curr = segs[k].tree[0];
        if (curr > lis) {
            lis = curr;
            max_k = k;
        }
    }
    cout << lis.first << '\n';

    stack<int> ans;
    pair<int, int> curr = make_pair(max_k, lis.second);
    while (curr.first >= 0) {
        ans.push(curr.second);
        curr = p[curr.first][curr.second];
    }

    while (!ans.empty()) {
        cout << a[ans.top()] << ' ';
        ans.pop();
    }
    cout << '\n';
}
