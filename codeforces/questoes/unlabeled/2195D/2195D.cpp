#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<ll> ans(n);
        for (int i=1; i<n-1; i++) {
            ans[i] = ((a[i-1] - a[i]) - (a[i] - a[i+1])) / 2;
        }

        {
            ll x = a[0];
            for (int i=1; i<n-1; i++) {
                x -= i * ans[i];
            }
            ans[n-1] = x / (n-1);
        }

        {
            ll x = a[n-1];
            for (int i=1; i<n-1; i++) {
                x -= (n-i-1) * ans[i];
            }
            ans[0] = x / (n-1);
        }

        for (int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}