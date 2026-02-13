#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second

/*
6
1 1 3 1 1 2
=> 9

1 3 1 2 => 2
2 3 2 2 - 2 = 7

*/

void solve() {
    int n;
    cin >> n;
    deque<int> dq(n);
    ll ans = 0;
    int big = INT32_MIN;
    for (int i=0; i<n; i++) {
        cin >> dq[i];
    }
    
    for (int i=0; i<n; i++) {
        int cost = max(dq[i], dq[(i+1)%n]);
        ans += cost;
        big = max(big, cost);
    }

    cout << ans - big << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}