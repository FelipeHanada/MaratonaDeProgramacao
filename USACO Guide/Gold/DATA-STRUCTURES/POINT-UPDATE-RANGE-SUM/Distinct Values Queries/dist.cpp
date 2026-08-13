#include <bits/stdc++.h>
using namespace std;


struct Fenwick {
    int n; vector<int> t;
    Fenwick(int n) : n(n), t(n, 0) { }
    void add(int i, int v) {
        for (; i<n; i=i|(i+1)) t[i] += v;
    }
    int get(int r) {
        int ans = 0;
        for (; r>=0; r=(r&(r+1))-1) ans += t[r];
        return ans;
    }
    int get(int l, int r) { return get(r) - get(l-1); }
};


int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> ans(q);
    vector<array<int,3>> query(q);
    for (int i=0; i<q; i++) {
        cin >> query[i][0] >> query[i][1];
        query[i][0]--;
        query[i][1]--;
        query[i][2] = i;
    }
    sort(query.begin(), query.end());
    reverse(query.begin(), query.end());

    Fenwick ft(n);
    int L = n;
    map<int, int> last;
    for (auto [ l, r, id ] : query) {
        while (L > l) {
            L--;
            if (last.count(a[L])) ft.add(last[a[L]], -1);
            ft.add(L, 1);
            last[a[L]] = L;
        }

        ans[id] = ft.get(l, r);
    }

    for (int x : ans) cout << x << '\n';
}