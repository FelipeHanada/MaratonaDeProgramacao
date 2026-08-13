#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    while (1) {
        int n, q;
        cin >> n >> q;
        if (!n) break;

        cout << "CASE# " << tt++ << ":\n";

        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        // O(n) <-- receber o input (não tem como fazer melhor)
        sort(a.begin(), a.end()); // O(nlogn) <-- ordenação do input

        map<int, int> m;
        for (int i=0; i<n; i++) {
            int x = a[i];
            if (!m.count(x)) m[x] = i;
            // m.count(x) roda em O(logn)
            // m[x] = i roda em O(logn)
        }
        // O(nlogn)

        while (q--) {
            int x;
            cin >> x;
            if (m.count(x)) {
                cout << x << " found at " << m[x] + 1 << '\n';
            } else {
                cout << x << " not found\n";
            }
            // O(logn)
        }
        // O(qlogn)

        // => O(nlogn + qlogn) = O((n + q) logn)
        // n, q <= 10^4
    }
}
