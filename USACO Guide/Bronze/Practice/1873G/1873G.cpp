#include <bits/stdc++.h>
using namespace std;


/*
ABBBBAAAAAAAAAABA
*/

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		
		int ans = 0;
		int small = INT32_MAX;
		int curr = 0;
		for (int i=0; i<s.size(); i++) {
			if (s[i] == 'A') curr++;
			else {
				ans += curr;
				small = min(small, curr);
				curr = 0;
			}
		}
		ans += curr;
		small = min(small, curr);
		
		if (s.front() == s.back() && s.front() == 'A')
			ans -= small;
		
		cout << ans << '\n';
	}
}