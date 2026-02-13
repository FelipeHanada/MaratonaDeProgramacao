#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    int lx = 0;
    int ux = 1e9;
    int curr; cin >> curr;
    int next;
    for (int i=1; i<n; i++) {
        cin >> next;
        if (curr < next) {
            // x must be atleast closer to curr than to next
            // x <= curr OR x <= curr + (next+curr)/2
            ux = min(ux, (curr+next)/2);
        } else if (curr > next) {
            // x must be closer to curr than to next
            // x >= next + (curr+next)/2
            lx = max(lx, (curr+next+1)/2);
        }
        curr = next;
    }

    if (lx <= ux) {
        cout << lx << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        solve();
    }
}