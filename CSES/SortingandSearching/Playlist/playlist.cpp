#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	int l=0, r=0;
	int ans = 0;
	set<int> window;
	while (l < n) {
		while (r < n && !window.count(a[r])) {
			window.insert(a[r]);
			r++;
		}
		
		ans = max(ans, (int)window.size());
		window.erase(a[l]);
		l++;
	}
	
	cout << ans << '\n';
}