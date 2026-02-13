#include <bits/stdc++.h>
using namespace std;



int query(int i) {
	cout << "? 1 1 " << i << '\n';
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int x;
		cin >> x >> x;
	}
	
	int q = query(1);
	if (q % 2) {
		// 1 is the root and val[1] = q;
		vector<int> qs(n+1);
		for (int i=2; i<=n; i++) qs[i] = query(i);
		
		cout << "! " << q << ' ';
		for (int i=2; i<=n; i++) {
			cout << qs[i] - q << ' ';
		}
		cout << '\n';
	} else {
		// some other vertex r is the root
		// val[1] + val[r] = q
		
		// fazer val[r] = -val[1] e saber qual é val[1] + val[r]
		if (q == 0) {
			cout << "? 2 1\n";
			fflush(stdout);
			q = query(1);
		}
		
		int val1 = q/2;
		cout << "? 2 1\n";
		fflush(stdout);
		val1 *= -1;
		
		vector<int> qs(n+1);
		for (int i=2; i<=n; i++) {
			qs[i] = query(i);
		}
		
		cout << "! " << val1 << ' ';
		for (int i=2; i<=n; i++) {
			cout << qs[i] - qs[1] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}