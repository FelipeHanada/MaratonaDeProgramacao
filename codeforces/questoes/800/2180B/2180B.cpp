#include <bits/stdc++.h>
using namespace std;


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		for (int i=1; i<n; i++) {
			cin >> t;
			s = min(s + t, t + s);
		}
		
		cout << s << '\n';
	}
}