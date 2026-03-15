#include <bits/stdc++.h>
using namespace std;


int query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

int main() {
    int n, t, k;
    cin >> n >> t >> k;
    
    int l = 0, r = n;
    // there are less than k zeros before l
    // there are >= k zeros before r
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (mid - query(1, mid) < k) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << "! " << r << '\n';
}
