#include <bits/stdc++.h>
using namespace std;


/*
5 9
15 12 18 3 8

a[i]%m = 6 3 0 3 8
a[i]   = 0 3 3 6 8
a[i]+m = 9 12 12 15 17


a[i] (i=0) = (9) 12 12 15 17 => 6 8 (9) 12 12 => 3+1+3+3 = 10
a[i] (i=1) = 9 (12) 12 15 17 => 8 9 (12) 12 15 => 4+3+0+3 = 10
a[i] (i=2) = 9 12 (12) 15 17 => 9 12 (12) 15 17 => 3+0+3+5 = 11
a[i] (i=3) = 9 12 12 (15) 17 => 12 12 (15) 17 18 => 3+3+2+3 = 11
a[i] (i=4) = 9 12 12 15 (17) => 12 15 (17) 18 21 => 5+2+1+4 = 12
*/

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<ll> a(n);
        for (int i=0; i<n; i++) {
        	cin >> a[i];
        	a[i] = a[i]%m + m;
		}
		sort(a.begin(), a.end());
		
		ll ans = INT32_MAX;
		for (int i=0; i<n; i++) {
			ll curr = 0;
			// there are i smaller items
			// and n-i-1 bigger items
			
			if (i <= n-i-1) {
				int j=0;
				for (; j<i; j++) curr += a[i] - a[j];
				j++;
				for (; j<=2*i; j++) curr += a[j] - a[i];

				int r = n-2*i-1;
				for (; j<n-r/2; j++) curr += a[j] - a[i];
				for (; j<n; j++) curr += a[i] - (a[j] - m);
				ans = min(ans, curr);
			} else {
				int j=0;
				int r = 2*i-n+1;
				for (; j<r/2; j++) curr += (a[j] + m) - a[i];
				for (; j<r; j++) curr += a[i] - a[j];
																
				for (; j<i; j++) curr += a[i] - a[j];
				j++;
				for (; j<n; j++) curr += a[j] - a[i];

				ans = min(ans, curr);
			}
		}
		
		cout << ans << '\n';
    }
}