#include <bits/stdc++.h>
using namespace std;

/*
9 5
3 5 2 3 3 5 8 1 2
4 6 2 4 6

p[] = -1 1 6 8 n n
s[] = -1 -1 4 5 6 n
*/


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	
	vector<int> p(m+1), s(m+1);
	// p[i] equals the minimum index such that a_1,...,a_{p[i]}
	// is sufficient to collect all b_1,...,b_i flowers
	// s[i]: a_{s[i]},...,a_n is suff. to collect all b_i,...,b_m flowers
	p.front() = -1;
	{
		int l=0;
		for (int i=0; i<m; i++) {
			while (l < n && a[l] < b[i]) l++;
			p[i+1] = l;
			l++;
		}
	}
	s.back() = n;
	{
		int r=n-1;
		for (int i=m-1; i>=0; i--) {
			while (r >= 0 && a[r] < b[i]) r--;
			s[i] = r;
			r--;
		}
	}
	
	//for (int x : p) cout << x << ' '; cout << '\n';
	//for (int x : s) cout << x << ' '; cout << '\n';
	
	int ans = INT32_MAX;
	for (int i=0; i<m; i++) {
		if (p[i] < s[i]) ans = 0;
		if (p[i] < s[i+1]) ans = min(ans, b[i]);
	}
	
	cout << (ans == INT32_MAX ? -1 : ans) << '\n';
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}