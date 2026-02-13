#include <bits/stdc++.h>
using namespace std;


/*
min(a) + max(a) is even
iff. min(a) and max(a) is even
	or min(a) and max(a) is odd
*/

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a.begin(), a.end());

		int ans = n;
		int i=0, j=n-1;
		while (i < j) {
			if (a[i] % 2) i++;
			else if (a[j] % 2) j--;
			else break;
		}
		ans = min(ans, i+n-1-j);
		i = 0, j = n-1;
		while (i < j) {
			if (!(a[i]%2)) i++;
			else if (!(a[j]%2)) j--;
			else break;
		}
		ans = min(ans, i+n-1-j);
		cout << ans << '\n';
	}
}
