#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i=1; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) cin >> b[i];
    for (int i=0; i<n; i++) cin >> c[i];

    a[0] = b[n-1] = 0;
    for (int i=1; i<n; i++) a[i] += a[i-1];
    for (int i=n-2; i>=0; i--) b[i] += b[i+1];

    int ans = INT32_MAX;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ans = min(ans, a[i] + b[i] + c[i] + a[j] + b[j] + c[j]);
        }
    }

    cout << ans << '\n';
}
