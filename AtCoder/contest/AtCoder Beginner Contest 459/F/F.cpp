#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll cost = 0;
    for (int i=0; i<n/2; i++) {
        if (a[i] >= a[n-i-1]) {
            ll moves = (a[i] - a[n-i-1]) / 2 + 1;
            a[i] -= moves;
            a[n-i-1] += moves;
            cost += moves;
        }
    }

    for (ll x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }    
}

/*
10
11 9 1 3 17 19 10 19 17 3

-1 +1
   -1 +1
      -1 +1

we can sub 1 from i < j and add 1 to j
    in (j - i) moves

a[1] < a[n] => 

10
11 9 1 3 17 19 10 19 17 3
=> 5 moves
6 9 1 3 17 19 10 19 17 8

6 9 1 3 17 19 10 19 17 8

*/