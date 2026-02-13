#include <bits/stdc++.h>
using namespace std;


/*
5 9
15 12 18 3 8

a[i]      =   0 3 3 6 8
prefix[i] = 0 0 3 3 6 8 9 12 12 15 17 (just extended)
prefix[i] = 0 0 3 6 12 20 29 41 53 68 85

prefix[i] = 0 0 3 6 12 20 29 41 53 68 85
                  ^
              L L R  R  R
prefix[i] = 0 0 3 6 12 20 29 41 53 68 85
              L L L  R  R  R
                     ^i      
*/

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		
		vector<ll> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
			a[i] %= m;
		}
		sort(a.begin(), a.end());
		
		vector<ll> prefix(2*n+1);
		for (int i=1; i<=n; i++) {
			prefix[i] = a[i-1];
			prefix[i+n] = prefix[i] + m;
		}
		for (int i=1; i<=2*n; i++) {
			prefix[i] += prefix[i-1];
		}
		
		ll ans = INT64_MAX;
		for (int i=n/2+1; i<=n/2+n; i++) {
			ll curr = prefix[i]-prefix[i-1];
			ll left = (n/2)*curr - (prefix[i-1] - prefix[i-1-n/2]);
			ll right = (prefix[i+(n-1)/2] - prefix[i-1]) - ((n-1)/2+1)*curr;
			ans = min(ans, left + right);
		}

		cout << ans << '\n';
	}
}