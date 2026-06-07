#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
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
    ll get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) +get(l, r, 2*x+2, mid, rx); 
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i=0; i<m; i++) cin >> a[i].first >> a[i].second;

    map<int, vector<pair<int, int>>> L, R;
    for (int i=0; i<m; i++) {
        L[a[i].first].push_back({ a[i].second, i });
        R[a[i].second].push_back({ -a[i].first, i });
    }
    for (auto &[l, v] : L) sort(v.begin(), v.end());
    for (auto &[r, v] : R) sort(v.begin(), v.end());

    vector<int> covers(m, 0);
    SegTree ls(n+1);
    vector<array<int, 3>> b(m);
    for (int i=0; i<m; i++) {
        b[i] = { a[i].second, -a[i].first, -i };
    }
    sort(b.begin(), b.end());
    for (int i=0; i<m; i++) {
        covers[-b[i][2]] = ls.get(-b[i][1], n+1);
        ls.add(-b[i][1], 1);
        // covers[-b[i][2]] = distance(ls.lower_bound(-b[i][1]), ls.end());
        // ls.insert(-b[i][1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        if (L.count(l) && R.count(r)) {
            // tests for case 2
            // there must be a carpet that starts in L and ends before R
            // and a carpet that ends in R and starts after L
            auto itl = lower_bound(L[l].begin(), L[l].end(), make_pair(r, INT32_MIN));
            auto itr = lower_bound(R[r].begin(), R[r].end(), make_pair(-l, INT32_MIN));
            if (itl != L[l].begin() && itr != R[r].begin()) {
                itl--;
                itr--;
                if (itl->first + 1 >= -itr->first) {
                    cout << "Yes\n";
                    continue;
                }
            }

            // tests for case 1
            auto it = lower_bound(L[l].begin(), L[l].end(), make_pair(r, INT32_MIN));
            if (it != L[l].end() && it->first == r && covers[it->second]) {
                cout << "Yes\n";
                continue;
            }
        }

        cout << "No\n";
    }
}

// 2 possibilities
// 1) one carpet covers [l, r], and the other is just inside
// 2) there are two carpets that covers [l, r]
//      => first one is [l, r'] where r' <= r
//      => other one is [l', r] where l <= l'

/*

case 2 is easy to find => binary search

case 1 is the hard one
we need to check for some interval [l, r] if there is
    a carpet [l', r'] such that l < l' <= r' < r

we can compute the number of carpets covered by some carpet
*/
