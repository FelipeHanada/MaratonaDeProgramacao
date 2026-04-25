#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() { _
    int n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int len = l; len <= 100; len++) {
        ll curr = 0;
        for (int i=0; i<n; i++) {
            curr += (a[i] / len) * len;
        }
        ans = max(ans, curr);
    }

    cout << ans << '\n';
}
