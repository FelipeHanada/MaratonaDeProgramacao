#include <bits/stdc++.h>
using namespace std;


int main() {
	int d, s;
	cin >> d >> s;
	
	vector<int> mins(d), maxes(d);
	int low = 0, high = 0;
	for (int i=0; i<d; i++) {
		cin >> mins[i] >> maxes[i];
		low += mins[i];
		high += maxes[i];
	}
	
	if (s < low || s > high) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	s -= low;
	for (int i=0; i<d; i++) {
		int new_i = min(maxes[i], mins[i] + s);
		s -= new_i - mins[i];
		cout << new_i << ' ';
	}
	cout << '\n';
}