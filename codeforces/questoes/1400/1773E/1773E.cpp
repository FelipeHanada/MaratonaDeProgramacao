#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	set<int> s;
	vector<vector<int>> towers(n);
	for (int i=0; i<n; i++) {
		int m;
		cin >> m;
		towers[i].resize(m);
		for (int j=0; j<m; j++) {
			cin >> towers[i][j];
			s.insert(towers[i][j]);
		}
	}
	
	// we only need to compute the number of splits,
	// because the number of combine is #splits + n-1
	
	// we only need to split a tower at a given height i
	// tower[i] != tower[i+1] and the next value expected after tower[i] isnt tower[i+1]
	
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<towers[i].size()-1; j++) {
			auto ub = s.upper_bound(towers[i][j]);
			if (towers[i][j] != towers[i][j+1]
				&& (ub == s.end() || *ub != towers[i][j+1])
			) {
				ans++;
			}
		}
	}
	
	cout << ans << ' ' << ans + n - 1 << '\n';
}
