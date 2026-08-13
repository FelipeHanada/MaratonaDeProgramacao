#include <bits/stdc++.h>
using namespace std;


/*
o 1 sempre tem que estar na posição 2

0 1 2 3 4 5 6 ... n-1

| 1 1 1 1 1 1 1 ... 1
i = 0 target = 1

4 5 6 ... n-1 2 3

0 -> 1
1 -> 4


1 0 1 1 0|


*/

struct Fenwick {
    int n;
    vector<int> a, t;
    Fenwick(int n) : n(n), a(n, 0), t(n, 0) { }
    void add(int i, int delta) {
        a[i] += delta;
        for (; i < n; i=i|(i+1)) {
            t[i] += delta;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r=(r&(r+1))-1) {
            ans += t[r];
        }
        return ans;
    }
    int get(int l, int r) {
        return get(r) - get(l-1);
    }
};

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        Fenwick ft(n);
        for (int i=0; i<n; i++) ft.add(i, 1);

        auto kth_one = [&](int k, int curr = 0) -> int {
            int l = curr - 1, r = n-1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (ft.get(curr, mid) >= k) r = mid;
                else l = mid;
            }
            return r;
        };

        vector<int> ans(n);
        int curr=0;
        for (int i=1; i<=n; i++) {
            // precisa encontrar o (i+1)-ésimo 1 a partir de curr
            int k = max(1, (i + 1) % (n - i + 1));

            if (k > ft.get(curr, n-1)) {
                k -= ft.get(curr, n-1);
                curr = 0;
            }

            int pos = kth_one(k, curr);
            ft.add(pos, -1);
            ans[pos] = i;
            curr = pos;
        }

        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}
