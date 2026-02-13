#include <bits/stdc++.h>
using namespace std;


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int l, a, b;
		cin >> l >> a >> b;
		int d = __gcd(l, b);
		cout << l - d + a % d << '\n';
	}
}