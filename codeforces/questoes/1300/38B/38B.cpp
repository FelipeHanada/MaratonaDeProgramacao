#include <bits/stdc++.h>
using namespace std;


char dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
char dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

int main() {
	string a, b;
	cin >> a >> b;
	
	
	int ans = 0;
	for (char r='a'; r<='h'; r++) {
		if (r == a[0]) continue;
		for (char c='1'; c<='8'; c++) {
			if (c == a[1]) continue;
			if (r == b[0] && c == b[1]) continue;

			bool ok = true;
			for (int i=0; ok && i<8; i++) {
				if (
					(r+dx[i] == a[0] && c+dy[i] == a[1])
					|| (r+dx[i] == b[0] && c+dy[i] == b[1])
				) {
					ok = false;
					break;
				}
			}
			
			if (!ok) continue;
			ans++;
		}
	}
	
	cout << ans << '\n';
}