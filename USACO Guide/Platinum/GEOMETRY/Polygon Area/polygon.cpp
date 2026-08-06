#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];
    
    ll area = 0;
    for (int i=0; i<n; i++) {
        area += (y[i] + y[(i+1)%n]) * (x[i] - x[(i+1)%n]);
    }

    cout << abs(area) << '\n';
}
