#include <bits/stdc++.h>
using namespace std;


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		
		int cnt = 0;
		bool ans = 0;
		for (int i=0; i<s.size()-1; i++) {
			if (s[i] == '(') {
				cnt++;
			} else {
				cnt--;
			}
			
			if (cnt == 0 ) ans = 1;
		}
		
		cout << (ans ? "YES" : "NO") << '\n';
	}		
}