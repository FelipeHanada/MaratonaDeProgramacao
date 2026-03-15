#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;
#define _0 first
#define _1 second

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            cout << w * x << '\n';
            h -= x;
        } else {
            cout << h * x << '\n';
            w -= x;
        }
    }
}
