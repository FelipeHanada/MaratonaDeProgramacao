#include <bits/stdc++.h>
using namespace std;


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		
		bool ok = true;
		for (int i=2; i<n; i+=2) {
			if (a[i] != a[i-1]) ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << '\n';
	}
}