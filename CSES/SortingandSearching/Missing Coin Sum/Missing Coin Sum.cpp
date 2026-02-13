#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	ll lower = 0;
	for (int i=0; i<n; i++) {
		if (a[i] <= lower + 1) {
			lower += a[i];
		} else {
			break;
		}
	}
	
	cout << lower + 1 << '\n';
}
