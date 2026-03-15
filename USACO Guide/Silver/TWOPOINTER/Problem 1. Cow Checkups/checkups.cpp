#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
3
1 3 2
3 2 1

1 1 1



*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    vector<ll> cnt(n+1, 0), sum(n+1, 0);
    for (int i=0; i<n; i++) {
        cnt[a[i]]++;
    }

    ll ans = 0;
    ll i=0, j=n-1;
    while (i < j) {
        ans += (i+1) * cnt[b[i]] + sum[b[i]];
        ans += (i+1) * cnt[b[j]] + sum[b[j]];

        cnt[a[i]]--; cnt[a[j]]--;
        sum[a[i]] += i+1; sum[a[j]] += i+1;
        i++; j--;
    }

    if (i == j && a[i] == a[j]) {
        ans += (i+1) * cnt[b[j]] + sum[b[j]];
    }

    for (ll i=0; i<n; i++) if (a[i] == b[i]) {
        if (i-1 >= 0) ans += i + (i * (i-1)) / 2;
        if (n-i-1 >= 0) ans += n-i-1 + ((n-i-1) * (n-i-2)) / 2;
    }

    cout << ans << '\n';
}
