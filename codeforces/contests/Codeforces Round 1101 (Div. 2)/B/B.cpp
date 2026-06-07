#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        ll ans = INT64_MAX;
        ll sum = 0;
        ll acc = 0;
        for (int i=0; i<n; i++) {
            sum += a[i];
            ans = min(ans, sum / (i+1));
            cout << ans << ' ';
        }
        cout << '\n';
    }
}
