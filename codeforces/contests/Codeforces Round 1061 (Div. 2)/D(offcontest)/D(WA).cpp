#include <bits/stdc++.h>
using namespace std;

/*

1 2 3 4 5 6

001
010
011
100
101
110
111
^
*/


int query(int i, int x) {
	cout << "? " << i << ' ' << x << '\n';
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

void solve() {
	int n;
	cin >> n;
	set<int> s;
	for (int i=1; i<n; i++) s.insert(i);
	
	int target = 0;
	int r = n;
	for (int d=__builtin_clz(1) - __builtin_clz(n); d>=0 && !s.empty(); d--) {
		int expected = r - (target | ((1<<d)-1));
		
		set<int> z, o;
		int count = 0;
		for (int i : s) {
			if (query(i, (1<<d))) {
				count++;
				o.insert(i);
			} else {
				z.insert(i);
			}
		}
		
		if (count < expected) {
			target |= (1<<d);
			swap(s, o);
		} else {
			swap(s, z);
			r = min(n, target | ((1<<d)-1));
		}
	}

	cout << "! " << (target ? target : 1) << '\n';
}

/*
8
3 2 5 7 8 6 1 4
*/

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}