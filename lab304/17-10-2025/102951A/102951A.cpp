#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> y[i];

    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ans = max(ans, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        }
    }

    cout << ans << '\n';
}
