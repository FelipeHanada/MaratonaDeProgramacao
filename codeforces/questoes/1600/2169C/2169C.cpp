#include <bits/stdc++.h>
using namespace std;


/*

prefix[i] = sum of all elements until i

after changing a (l, r) interval, the sum changes
(r-l+1)*(l+r) - (prefix[r] - prefix[l-1])
= rl + rr - ll -rl + l + r - prefix[r] + prefix[l-1]
= rr - ll + l + r - prefix[r] + prefix[l-1]
= (rr + r - prefix[r]) - (ll - l - prefix[l-1])

= (rr + r - prefix[r]) - (ll - l - prefix[l-1])
= (rr + r - prefix[r]) - ((l-1)(l-1) + l-1 - prefix[l-1])
= f(r) - f(l-1)
para f(x) = xx + x - prefix[x]

(l-1)(l-1) = ll -2l + 1
(l-1)(l-1) + l - 1 = ll - l
*/

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		
		vector<ll> prefix(n+1);
		prefix[0] = 0;
		for (int i=1; i<=n; i++) {
			prefix[i] = prefix[i-1] + a[i-1];
		}
		
		ll mn = 0;
		ll ans = INT32_MIN;
		ll sum = 0;
		for (ll l=1; l<=n; l++) {
			ans = max(ans, l*l+l-prefix[l] - mn);
			mn = min(mn, l*l+l-prefix[l]);
			
			sum += a[l-1];
		}
		
		cout << sum + ans << '\n';
	}
}
