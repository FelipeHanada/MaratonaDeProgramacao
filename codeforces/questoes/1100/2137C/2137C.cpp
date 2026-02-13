#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
k* = argmax { a*k + b/k } such that k|b

we are looking for a pair of integers a' b' that maximizes a'+b'
	with a'*b' constant (a*b*b/j = a*b)

by the rectangular principle: the pair a',b' that maximizes a'+b'
	is such that a' and b' are further apart

I) a and b are odd
	k = b resolves the problem since a*b is odd and b/b=1 is odd too

II) a is odd and b is even
	k must be even (if k is odd, a*k will be odd and b/k will be even)
	
	if 4|b, k = b/2 solve it
		a*k will be even and b/k=2
	if not, we can prove that no k can make a*k+b/k even
	
III) a is even and b is odd
	we cannot solve it

IV) a and b are even
	b/k must be even
	k = b/2 solve it since b/k=2
*/

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		
		if (a % 2) {
			if (b % 2) {
				cout << a * b + 1 << '\n';
			} else {
				if (b % 4) {
					cout << "-1\n";
				} else {
					cout << a*b/2 + 2 << '\n';
				}
			}
		} else {
			if (b % 2) {
				cout << "-1\n";
			} else {
				cout << a*b/2 + 2 << '\n';
			}
		}
	}
}