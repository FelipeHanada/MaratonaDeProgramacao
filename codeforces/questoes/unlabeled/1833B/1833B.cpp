#include <bits/stdc++.h>
using namespace std;


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<array<int,2>> a(n);
		vector<int> b(n);
		for (int i=0; i<n; i++) {
			cin >> a[i][0];
			a[i][1] = i;
		}
		for (int i=0; i<n; i++) cin >> b[i];
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		vector<int> ans(n, -1);
		for (int i=0; i<n; i++) {
			ans[a[i][1]] = b[i];
		}
		
		for (int i=0; i<n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}