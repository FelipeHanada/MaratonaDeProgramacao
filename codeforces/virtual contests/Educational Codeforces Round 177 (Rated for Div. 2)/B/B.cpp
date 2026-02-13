#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	int n, k;
	ll x;
	cin >> n >> k >> x;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	vector<ll> prefix(n+1);
	prefix[0] = 0;
	for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] + a[i-1];
	
	ll ans = 0;
	for (int i=0; i<n; i++) {
		// prefix[n]-prefix[i]+(prefix[n]*(k-j)) >= x
		// we need to find max j that satisfies
		// -j >= (x - prefix[n] + prefix[i]) / prefix[n] - k
		// j <= (k * prefix[n] - x + prefix[n] - prefix[i]) / prefix[n]
		ll j = (k * prefix[n] - x + prefix[n] - prefix[i]) / prefix[n];
		if (j > 0) ans += j;
	}
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
