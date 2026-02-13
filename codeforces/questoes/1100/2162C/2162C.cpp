#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (__builtin_clz(a) > __builtin_clz(b)) {
            cout << "-1\n";
            continue;
        }

        // there is always possible by setting single bits (the number of bits is at most 64~63)
        deque<int> ans;
        int p = 1;
        while (a | b) {
            if ((a & 1) != (b & 1)) {
                ans.push_back(p);
            }
            p <<= 1;
            a >>= 1;
            b >>= 1;
        }

        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
