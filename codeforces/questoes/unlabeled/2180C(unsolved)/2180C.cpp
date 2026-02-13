#include <bits/stdc++.h>
using namespace std;


int flog2(int x) {
	return __builtin_clz(1) - __builtin_clz(x);
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		
		while (k > 2) {
			cout << n << ' ' << n << ' ';
			k -= 2;
		}
		if (k == 1) {
			cout << n << ' ';
		} else {
			int a = 0, b = 0;
			for (int j=flog2(n); j>=0; j--) {
				if (n & (1<<j)) {
					a |= (1<<j);
				} else if ((a|(1<<j)) <= n) {
					a |= (1<<j);
					b |= (1<<j);
				}
			}
			cout << a << ' ' << b << ' ';
		}
		cout << '\n';
	}
}