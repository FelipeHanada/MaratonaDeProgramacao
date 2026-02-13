#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        j--; k--;
        deque<int> p;
        {
            int i=0;
            for (; n; i++, n/=10) {
                p.push_back(i);
            }
        }

        deque<int> a, b;
        {
            int i=0;
            do {
                if (j == i) {
                    a = p;
                }
                if (k == i) {
                    b = p;
                }
                i++;
            } while (next_permutation(p.begin(), p.end()));
        }

        int ans = 0;
        for (int i=0; i<p.size(); i++) {
            if (a[i] == b[i]) ans++;
        }

        cout << ans << "A" << p.size() - ans << "B\n";
    }
}