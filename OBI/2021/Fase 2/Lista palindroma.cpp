#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int i=0, j = n-1;
    ll x = a[i], y = a[j];
    while (j - i + 1 > 1) {
        if (x == y) {
            x = a[++i];
            y = a[--j];
        } else if (x < y) {
            x += a[++i];
            ans++;
        } else {
            y += a[--j];
            ans++;
        }
    }

    cout << ans << '\n';
}