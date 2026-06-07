#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct SegTree {
    int X;
    int size;
    vector<ll> cnt;
    vector<vector<pair<int, int>>> prefix, suffix;
    SegTree(int n, int x) {
        X = x;
        size = 1;
        while (size < n) size *= 2;
        cnt.assign(size*2, 0);
        prefix.assign(size*2, vector<pair<int, int>>(1, { 0, -1 }));
        suffix.assign(size*2, vector<pair<int, int>>(1, { 0, -1 }));
    }
    int gcd(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return __gcd(a, b);
    }
    ll merge(
        ll cnt1, const vector<pair<int, int>> &pre1, const vector<pair<int, int>> &suf1,
        ll cnt2, const vector<pair<int, int>> &pre2, const vector<pair<int, int>> &suf2,
        vector<pair<int, int>> &pre3, vector<pair<int, int>> &suf3
    ) {
        pre3 = pre1;
        suf3 = suf2;

        for (auto [size, v] : pre2) {
            int g = gcd(pre3.back().second, v);
            if (g == pre3.back().second) pre3.back().first += size;
            else pre3.push_back(make_pair(size, g));
        }

        for (auto [size, v] : suf1) {
            int g = gcd(suf3.back().second, v);
            if (g == suf3.back().second) suf3.back().first += size;
            else suf3.push_back(make_pair(size, g));
        }

        ll cnt3 = cnt1 + cnt2;
        for (int i=1; i<suf1.size(); i++) {
            for (int j=1; j<pre2.size(); j++) {
                if (gcd(suf1[i].second, pre2[j].second) == X) {
                    cnt3 += ll(suf1[i].first) * pre2[j].first;
                }
            }
        }

        return cnt3;
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            cnt[x] = (v == X);
            prefix[x].assign(1, { 0, -1 });
            suffix[x].assign(1, { 0, -1 });
            prefix[x].push_back({ 1, v });
            suffix[x].push_back({ 1, v });
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        
        cnt[x] = merge(
            cnt[2*x+1], prefix[2*x+1], suffix[2*x+1], 
            cnt[2*x+2], prefix[2*x+2], suffix[2*x+2], 
            prefix[x], suffix[x]
        );
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    auto get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return make_tuple(cnt[x], prefix[x], suffix[x]);
        if (lx >= r || rx <= l) return make_tuple(0LL, (vector<pair<int,int>>){{0, -1}}, (vector<pair<int,int>>){{0, -1}});
        int mid = (lx + rx) / 2;
        auto [cntl, prel, sufl] = get(l, r, 2*x+1, lx, mid);
        auto [cntr, prer, sufr] = get(l, r, 2*x+2, mid, rx);

        vector<pair<int, int>> pre, suf;
        ll cnt = merge(
            cntl, prel, sufl,
            cntr, prer, sufr,
            pre, suf
        );
        return make_tuple(cnt, pre, suf);
    }
    auto get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, x;
    cin >> n >> q >> x;
    SegTree segtree(n, x);
    for (int i=0; i<n; i++) {
        int y;
        cin >> y;
        segtree.set(i, y);
    }

    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            segtree.set(a-1, b);
        } else {
            cout << get<0>(segtree.get(a-1, b)) << '\n';
        }
    }
}
