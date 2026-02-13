#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] < 0) a[i] = -a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i=0; i<n; i++) {
        auto ub = upper_bound(a.begin(), a.end(), 2*a[i]);
        ans += distance(a.begin()+i+1, ub);
    }
    cout << ans << '\n';
}