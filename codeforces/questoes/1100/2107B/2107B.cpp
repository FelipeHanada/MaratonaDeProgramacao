#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 0, small=INT32_MAX, big=INT32_MIN;
    int q_big = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum += x;
        small = min(small, x);
        if (x  > big) {
            big = x;
            q_big = 1;
        } else if (x == big) {
            q_big++;
        }
    }

    if (big - (q_big > 1 ? 0 : 1) - small > k || !(sum % 2)) {
        cout << "Jerry\n";
    } else {
        cout << "Tom\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}