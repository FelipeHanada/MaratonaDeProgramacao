#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second


struct pii_hash {
    int operator()(const pii& p) {
        return hash<int>()(p.f) ^ (hash<int>()(p.s) << 1);
    }
};

struct LISSegTree {
    int size;
    vector<int> lis;
    vector<int> count;
    LISSegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lis.assign(size*2, 0);
        count.assign(size*2, 1);
    }
    void set(int i, int v, int c, int x, int lx, int rx) {
        if (rx - lx == 1) {
            lis[x] = v;
            count[x] = c; 
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, c, 2*x+1, lx, mid);
        } else {
            set(i, v, c, 2*x+2, mid, rx);
        }
        lis[x] = max(lis[2*x+1], lis[2*x+2]);
        count[x] = 0;
        if (lis[2*x+1] == lis[x]) count[x] += count[2*x+1];
        if (lis[2*x+2] == lis[x]) count[x] += count[2*x+2];
    }
    void set(int i, int v, int c) { set(i, v, c, 0, 0, size); }
    void add(int v) {
        auto [curr_lis, curr_c] = get(0, v);
        if (curr_lis + 1 == lis[size-1+v]) {
            curr_c += count[size-1+v];
        }
        set(v, curr_lis + 1, curr_c);
    }
    pii get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return make_pair(lis[x], count[x]);
        if (lx >= r || rx <= l) return make_pair(0, 0);
        int mid = (lx + rx) / 2;

        pii left = get(l, r, 2*x+1, lx, mid);
        pii right = get(l, r, 2*x+2, mid, rx);
        pii ans = make_pair(max(left.f, right.f), 0);
        if (left.f == ans.f) ans.s += left.s;
        if (right.f == ans.f) ans.s += right.s;
        return ans;
    }
    pii get(int l, int r) { return get(l, r, 0, 0, size); }
    void get_all_equal(int l, int r, int v, int x, int lx, int rx, unordered_set<pii, pii_hash>& out) {
        if (rx - lx == 1) {
            out.insert(x - size);
            return;
        }
    }
    unordered_set<pii, pii_hash> get_ant(int i) {
        
    }
};

int main() {
    int n;
    cin >> n;

    vector<pii> cities(n);
    for (int i=0; i<n; i++) {
        cin >> cities[i].f >> cities[i].s;
    }
    sort(cities.begin(), cities.end());

    LISSegTree segtree(n);
    for (auto city : cities) {
        segtree.add(city.s);
    }

    for (int i=0; i<n; i++) {
        cout << segtree.lis[segtree.size-1+i] << ' ';
    }
    cout << '\n';

    for (int i=0; i<n; i++) {
        cout << segtree.count[segtree.size-1+i] << ' ';
    }
    cout << '\n';
}
