#include <bits/stdc++.h>
using namespace std;



// the amount of water needed to fill the tank in function of h (height of the walls) is monotonic
// lets run binary search to find the maximum h such that the water needed is at most x

#define ll long long

constexpr int MAX_N = 2e5;
int n, x;
int a[MAX_N];

bool check(ll h) {
    ll water = 0;
    for (int i=0; i<n; i++) {
        water += max((ll)0, h - a[i]);
        if (water > x) return false;
    }
    return true;
}

void solve() {
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll low = 0; ll high = INT64_MAX >> 12;
    while (high - low > 1) {
        ll mid = (low + high) / 2;

        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
