#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> fac(n+1);
    fac[0] = 1;
    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;

    cout << (fac[n]/fac[n/2]/fac[n/2])/2 * (fac[n/2]/(n/2)) * (fac[n/2]/(n/2)) << '\n';
}
