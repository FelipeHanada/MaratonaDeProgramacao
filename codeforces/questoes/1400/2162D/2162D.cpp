#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    
    int psum, asum;
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r + 1) / 2;
        cout << "1 1 " << mid << '\n';
        fflush(stdout);
        cin >> psum;
        cout << "2 1 " << mid << '\n';
        fflush(stdout);
        cin >> asum;

        if (psum == asum) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << "1 1 " << n << '\n';
    fflush(stdout);
    cin >> psum;
    cout << "2 1 " << n << '\n';
    fflush(stdout);
    cin >> asum;

    cout << "! " << l + 1 << ' ' << l + (asum - psum) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
