#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];
        sort(b.begin(), b.end());

        ll small = 0, big = 0;
        int j = 0;
        for (int i=0; i<n; i++) {
            while (j < m && b[j] < i+1) j++;

            if (j < m && b[j] == i + 1) {
                tie(small, big) = make_tuple(
                    min(small + a[i], -big-a[i]),
                    max(big + a[i], -small-a[i])
                );
            } else {
                small += a[i];
                big += a[i];
            }
        }

        cout << big << '\n';
    }
}
