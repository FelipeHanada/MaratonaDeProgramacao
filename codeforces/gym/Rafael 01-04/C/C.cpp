#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        deque<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<ll> suff(n, 0);
        for (int i=n-2; i>=0; i--) suff[i] = suff[i+1] - a[i+1];


        ll ans = INT64_MIN;
        
        ll curr = 0;
        for (int i=1; i<n; i++) {
            curr += -a[i];
        }
        ans = max(ans, curr);

        curr = a[0];
        ans = max(ans, curr + suff[1]);
        for (int i=1; i<n-1; i++) {
            curr += abs(a[i]);
            ans = max(ans, curr + suff[i+1]);
        }
        
        cout << ans << '\n';
    }
}
