#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {
}

/*
paints i and j can be used to paint the fence
	iff. a[i] + a[j] >= n
	and they can be used to paint in
		2 * (1 + a[i] + a[j] - n)


a naive approuch leads to an O(N^2) algo.

for each paint i, we can compute the number of paints j > i that
	can be used to paint


*/

void solve() {
	int n, m;
	cin >> n >> m;
	deque<ll> a(m);
	for (int i=0; i<m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	ll maxed = 0;
	while (!a.empty() && a.back() == n) {
		maxed++;
		a.pop_back();
		m--;
	}
	vector<ll> suffix(m+1);
	suffix[m] = 0;
	for (int i=m-1; i>=0; i--) {
		suffix[i] = suffix[i+1] + a[i];
	}
	
	ll ans = 0;
	for (int i=0; i<m; i++) {
		auto lb = lower_bound(a.begin(), a.end(), n - a[i]);
		int k = distance(a.begin(), lb);

		if (lb == a.end()) continue;
		if (*lb <= a[i]) ans += (1 + a[i] - n) * (m - k -1) + suffix[k] - a[i];
		else ans += (1 + a[i] - n) * (m - k) + suffix[k];
	}
	
	cout << ans + (maxed*(maxed-1)*(n-1)) + 2*(suffix[0]*maxed) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
