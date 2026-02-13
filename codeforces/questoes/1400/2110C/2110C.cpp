#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		
		vector<array<int, 2>> h(n);
		for (int i=0; i<n; i++) cin >> h[i][0] >> h[i][1];
		
		int l=0, r=0;
		vector<int> ls(n);
		bool possible = 1;
		for (int i=0; i<n; i++) {
			if (a[i] == 1) {
				l++;
				r++;
			} else if (a[i] == -1) {
				r++;
			}
			
			l = max(l, h[i][0]);
			r = min(r, h[i][1]);
			if (l > r) possible = 0;
			
			ls[i] = l;
		}
				
		if (!possible) {
			cout << "-1\n";
		} else {
			stack<int> ans;
			
			for (int i=n-1; i>0; i--) {
				if (a[i] == 1 || (a[i] == -1 && ls[i-1] < l)) {
					ans.push(1);
					l--;
				} else {
					ans.push(0);
				}
			}
			
			ans.push(l);
			
			while (!ans.empty()) {
				cout << ans.top() << ' ';
				ans.pop();
			}
			cout << '\n';
		}
	}
}