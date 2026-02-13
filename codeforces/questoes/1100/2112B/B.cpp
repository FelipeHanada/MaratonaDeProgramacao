#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	/* 
	if the array is already beautiful => cost = 0
	if not:

	if there is an index i such that a[i-1] > a[i] < a[i+1] (a[i-1] < a[i] > a[i+1])
		=> WLOC suppose that a[i-1] <= a[i+1]
			we can make a[i], a[i+1] => a[i] (a[i-1], a[i] => a[i+1])
	
	if there is no such index, the array is sorted
		we can prove that a sorted array that is not beautiful cannot
			be made bautiful by this operation
	*/
	
	bool beautiful = 0;
	bool asc = 1, desc = 1;
	for (int i=0; i<n-1 && !beautiful; i++) {
		if (abs(a[i] - a[i+1]) <= 1) beautiful = 1;
		if (a[i] < a[i+1]) desc = 0;
		if (a[i] > a[i+1]) asc = 0;
	}
	
	if (beautiful) {
		cout << "0\n";
		return;
	}
	if (asc || desc) {
		cout << "-1\n";
		return;
	}
	cout << "1\n";
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}