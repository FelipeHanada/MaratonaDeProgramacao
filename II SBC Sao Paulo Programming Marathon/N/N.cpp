#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n+2);
    for (int i=0; i<n+2; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll s = a.back(); a.pop_back();

    ll sum = 0;
    for (int i=0; i<n+1; i++) sum += a[i];

    ll m = sum - s * (n - 1);
    a.erase(find(a.begin(), a.end(), m));

    cout << s << ' ' << m << '\n';
    for (int i=n-1; i>=0; i--) cout << -a[i]+s << ' ';
    cout << '\n';
}

/*
3
8 3 7 5 6

4
0 0 0 0 0 0
*/