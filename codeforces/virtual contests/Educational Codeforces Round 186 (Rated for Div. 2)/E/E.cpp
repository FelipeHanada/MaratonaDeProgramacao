#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    map<int, int> a;
    for (int i=0; i<m; i++) {
    	int x;
    	cin >> x;
    	a[x]++;
    }
    
    vector<array<int, 2>> p(n);
   	for (int i=0; i<n; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	p[i] = {x, z-y};
    	k -= y;
    }
    sort(p.begin(), p.end());
    
    int ans = 0;
    int l = 0;
    multiset<int> costs;
	for (int j=1; j<=m; j++) {
		while (l < n && p[l][0] <= j) costs.insert(p[l++][1]);
		for (int i=0; i<a[j]; i++) {
            if (!costs.empty()) {
                costs.extract(*(--costs.end()));
                ans++;
            }
        }
	}
	
	while (!costs.empty() && k >= *costs.begin()) {
		k -= *costs.begin();
		costs.extract(*costs.begin());
		ans++;
	}
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
