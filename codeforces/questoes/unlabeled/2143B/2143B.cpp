#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(k);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<k; i++) {
			cin >> b[i];
		}
												
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		sort(b.begin(), b.end());
															
		ll ans = 0;
		int ai=0, bj=0;
		while (ai < n && bj < k && b[bj] <= n-ai) {
			for (int i=0; i<b[bj]-1; i++) {
				ans += a[ai++];
			}
			ai++;
			bj++;
		}
																														
		while (ai < n) ans += a[ai++];																															
		
		cout << ans << '\n';
	}
}