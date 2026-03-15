#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        map<int, set<int>> prefixes;
        for (int i=0; i<n; i++) prefixes[0].insert(i);
        int l;
        for (l=k-1; l>=0; l--) {
            map<int, set<int>> next, next2;

            for (auto [prefix, pos] : prefixes) {
                for (int j : pos) {
                    next[prefix | (a[j] & (1<<l))].insert(j);
                }
            }

            for (auto [prefix, pos] : next) {
                if (pos.size() > 1) next2[prefix] = pos;
            }

            if (next2.empty()) {
                break;
            } else {
                swap(prefixes, next2);
            }
        }

        array<int,4> best = {INT32_MIN, -1, -1, -1};
        for (auto [prefix, pos] : prefixes) {
            int p = *(pos.begin()), q = *(pos.rbegin());
            int x = 0;
            for (int i=k-1; i>l; i--) {
                if (!(prefix & (1 << i))) {
                    x |= (1<<i);
                }
            }
            for (int i=l; i>=0; i--) {
                if ((a[p]&(1<<i)) == (a[q]&(1<<i)) && !(a[q]&(1<<i))) {
                    x |= (1<<i);
                }
            }

            best = max(best, { (a[p]^x) & (a[q]^x), p, q, x });
        }

        cout << best[1] + 1 << ' ' << best[2] + 1 << ' ' << best[3] << '\n';
    }
}
