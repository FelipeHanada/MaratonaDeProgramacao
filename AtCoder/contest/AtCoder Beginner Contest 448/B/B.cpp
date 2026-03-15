#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;

int main() { _
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (int i=0; i<m; i++) cin >> c[i];
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];


    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += min(c[a[i]-1], b[i]);
        c[a[i]-1] -= min(c[a[i]-1], b[i]);
    }

    cout << ans << "\n";
}
