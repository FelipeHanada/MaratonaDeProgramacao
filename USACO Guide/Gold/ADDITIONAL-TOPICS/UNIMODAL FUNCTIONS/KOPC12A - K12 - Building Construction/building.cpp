#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> h(n), c(n);
        for (int i=0; i<n; i++) cin >> h[i];
        for (int i=0; i<n; i++) cin >> c[i];
        
        auto f = [&](int k) -> ll {
            ll cost = 0;
            for (int i=0; i<n; i++) {
                cost += abs(h[i] - k) * (ll)c[i];
            }
            return cost;
        };

        int l = -1, r = 10000;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (f(mid) > f(mid + 1)) l = mid;
            else r = mid;
        }

        cout << f(r) << '\n';
    }
}

/*
the cost function for a given building is
    f(k) = abs(k - h) * c
    this function is convex

since the sum of convex functions is also a convex function
    and all convex functions are unimodal, we can use binary search to find the answer
*/
