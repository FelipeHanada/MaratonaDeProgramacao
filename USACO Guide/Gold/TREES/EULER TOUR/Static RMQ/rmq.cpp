#include <bits/stdc++.h>
using namespace std;


inline int flog2(int x) { return __builtin_clz(1) - __builtin_clz(x); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> st;
    st.push_back(a);
    for (int k=1; (1<<k) <= n; k++) {
        st.push_back(vector<int>());
        for (int i=0; i+(1<<k) <= n; i++) {
            st[k].push_back(min(st[k-1][i], st[k-1][i+(1<<(k-1))]));
        }
    }

    auto st_min = [&](int l, int r) {
        int k = flog2(r - l);
        return min(st[k][l], st[k][r-(1<<k)]);
    };

    while (q--) {
        int l, r; cin >> l >> r;
        cout << st_min(l, r) << '\n';
    }
}