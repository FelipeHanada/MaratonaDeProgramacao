#include <bits/stdc++.h>
using namespace std;

/*
a b a+b a+2b 2a+3b
*/

constexpr int MOD = 998244353;

#define pii pair<int, int>

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> w(n);
		for (int i=0; i<n; i++) cin >> w[i];

		vector<vector<int>> adj(n);
		vector<array<int,3>> edges;
		for (int i=0; i<m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			adj[x].push_back(y);
			edges.push_back({w[y], x, y});
		}
		sort(edges.begin(), edges.end());
	
		map<pii, int> dp;
		// dp[{i, w}] = number of paths modMOD that ends in i 
		// 							and the weight of the previous to last vertex is w
	
		int ans = edges.size();
		for (auto [v, x, y] : edges) {
			dp[(pii){y, w[x]}] = (dp[(pii){y, w[x]}] + 1) % MOD;
			
			for (int next : adj[y]) {
				if (dp.count((pii){y, w[next]-w[y]})) {
					int delta = dp[(pii){y, w[next]-w[y]}];
					dp[(pii){next, w[y]}] = (dp[(pii){next, w[y]}] + delta) % MOD;
					ans = (ans + delta) % MOD;
				}
			}
		}
	
		cout << ans << '\n';
	}
}
