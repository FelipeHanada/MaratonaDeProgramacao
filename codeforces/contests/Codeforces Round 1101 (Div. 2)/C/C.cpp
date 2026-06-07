#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        int mid = (lx + rx) / 2;
        tree[2*x+1] += tree[x];
        tree[2*x+2] += tree[x];
        tree[x] = 0;
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x] += v;
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

        SegTree segtree(a);
        int last = 0;
        for(int i=0; i<n; i++) {
            if (s[i] == 'I') {
                segtree.add(last+1, segtree.get(last) + 1);
                last++;
            } else if (s[i] == 'E') {
                segtree.add(0, last + 1, 1);
            } else {
                segtree.add(0, last + 1, 1);
                segtree.add(last+1, segtree.get(last));
            }
        }

        int ans = 0;
        for (int i=0; i<=last; i++) {

        }

        cout << segtree.get(last) << '\n';
    }
}


/*
6
5 2 2
EIAIE

avl[]  =    0 
used[] =    

I => adiciona uma nova mesa sempre que der
E => aumenta o uso máximo de todas as soluções
*/