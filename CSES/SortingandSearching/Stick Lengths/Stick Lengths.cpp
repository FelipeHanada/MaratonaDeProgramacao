#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += abs(a[n/2] - a[i]);
    }
    cout << ans << '\n';
}