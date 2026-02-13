#include <bits/stdc++.h>
using namespace std;

#define _1 first
#define _2 second
#define pii pair<int, int>
#define ll long long 


void precompute() {

}

// se é par, simplesmente max subarray sum
// se é impar, alice tem uma jogada ótima

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    ll curr, best, curr_;
    curr = best = curr_ = INT32_MIN;
    for (int i=0; i<n; i++) {
        curr = max(curr + a[i], a[i]);
        curr_ = max(curr_ + a[i], curr + b[i]);
        best = max(best, (k % 2) ? curr_ : curr);
    }

    cout << best << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
