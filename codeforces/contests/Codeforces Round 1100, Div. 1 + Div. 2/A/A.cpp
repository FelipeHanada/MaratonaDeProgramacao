#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int big = INT32_MIN, small = INT32_MAX;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            big = max(big, x);
            small = min(small, x);
        }

        cout << (big - small + 1) / 2 << '\n';
    }
}
