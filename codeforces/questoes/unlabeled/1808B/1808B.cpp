#include <bits/stdc++.h>
using namespace std;


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(m, vector<int>(n, 0));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> a[j][i];
			}
		}
		for (int i=0; i<m; i++) sort(a[i].begin(), a[i].end());
		
		long long ans = 0;
		for (int j=0; j<m; j++) {
			for (int i=0; i<n; i++) {
				ans += (i - (n - i - 1)) * (long long)a[j][i];
			}
		}
		cout << ans << '\n';
	}
}