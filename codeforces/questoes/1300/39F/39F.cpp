#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1e9;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<array<int, 2>> frogs;
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		frogs.push_back({x, 0});
	}
	
	for (int i=0; i<k; i++) {
		int x;
		cin >> x;

		for (auto &[d, v] : frogs)
			if (x % d == 0) v++;
	}
	
	vector<int> ans;
	int small = INT32_MAX;
	for (int i=0; i<m; i++) small = min(small, frogs[i][1]); 
	for (int i=0; i<m; i++) if (frogs[i][1] == small) ans.push_back(i);

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x + 1 << ' ';
	}
	cout << '\n';
}
