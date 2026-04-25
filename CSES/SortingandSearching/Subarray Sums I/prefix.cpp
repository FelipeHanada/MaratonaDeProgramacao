#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    map<ll, int> cnt; cnt[0] = 1;
    ll ans = 0, sum = 0;
    for (int i=0; i<n; i++) {
        sum += a[i];
        ans += cnt[sum - x];
        cnt[sum]++;
    }

    cout << ans << '\n';
}