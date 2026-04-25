#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    ll total = 0;
    for (int i=0; i<n; i++) total += a[i];


    ll ans = INT64_MAX;
    for (int i=0; i<(1<<n); i++) {
        ll sum = 0;
        for (int j=0; j<n; j++) if (i & (1 << j)) {
            sum += a[j];
        }

        ans = min(ans, abs(sum - (total - sum)));
    }

    cout << ans << '\n';
}
