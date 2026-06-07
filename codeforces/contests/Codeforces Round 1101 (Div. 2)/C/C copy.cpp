#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
 

struct SegTree {
    int size;
    vector<int> tree;
    vector<int> lazy;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
        lazy.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += lazy[x];
            lazy[x] = 0;
            return;
        }
        int mid = (lx + rx) / 2;
        lazy[2*x+1] += lazy[x];
        lazy[2*x+2] += lazy[x];
        lazy[x] = 0;
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] += v;
            return;
        }
        int mid = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, mid);
        add(l, r, v, 2*x+2, mid, rx);
    }
    void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
    void add(int i, int v) { add(i, i+1, v); }
    int get(int i, int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx - lx == 1) return tree[x];
        int mid = (lx + rx) / 2;
        if (i < mid) return get(i, 2*x+1, lx, mid);
        else return get(i, 2*x+2, mid, rx);
    }
    int get(int i) { return get(i, 0, 0, size); }
};

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b; string s;
        cin >> n >> a >> b >> s;
 
        SegTree segtree(a+5);
 
        for (int i=0; i<n; i++) {
            map<int, int> next = dp;
 
            for (auto [empty, rem] : dp) {
                if (s[i] == 'I') {
                    if (empty > 0) {
                        if (!next.count(empty-1)) next[empty-1] = rem+b-1;
                        else next[empty-1] = min(next[empty-1], rem+b-1);
                    }
                } else if (s[i] == 'E') {
                    if (rem > 0) next[empty]--;
                } else {
                    if (empty > 0) {
                        if (!next.count(empty-1)) next[empty-1] = rem+b-1;
                        else next[empty-1] = min(next[empty-1], rem+b-1);
                    }
                    if (rem > 0) next[empty]--;
                }
            }
 
            swap(dp, next);
        }
 
        int ans = 0;
        for (auto [ empty, rem ] : dp) {
            int score = (a - empty) * b - rem;
            ans = max(ans, score);
        }
 
        cout << ans << '\n';
    }
 
    /*
    dp sol.
 
    number of empty tables
    number of seats on non-empty tables
    */
}