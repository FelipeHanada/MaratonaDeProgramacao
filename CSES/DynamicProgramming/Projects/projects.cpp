#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	vector<array<int,3>> proj(n);
	set<int> s;
	for (int i=0; i<n; i++) {
		cin >> proj[i][0] >> proj[i][1] >> proj[i][2];
		s.insert(proj[i][0]);
		s.insert(proj[i][1]);
	}
	{
		unordered_map<int, int> comp;
		int i=0;
		for (int x : s) {
			comp[x] = i++;
		}
		for (int i=0; i<n; i++) {
			proj[i][0] = comp[proj[i][0]];
			proj[i][1] = comp[proj[i][1]];
		}
	}
	sort(proj.begin(), proj.end());	
	
	vector<ll> dp(s.size()+1, 0);
	int j=0;
	for (int i=0; i<=s.size(); i++) {
		if (i > 0) dp[i] = max(dp[i], dp[i-1]);
		while (j < n && i == proj[j][0]) {
			dp[proj[j][1]+1] = max(dp[proj[j][1]+1], proj[j][2] + dp[i]);
			j++;
		}
	}
	
	cout << dp[s.size()] << '\n';
}