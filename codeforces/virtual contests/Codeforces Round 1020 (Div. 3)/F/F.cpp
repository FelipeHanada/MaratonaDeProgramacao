#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	array<ll, 2> sz;
	if (s[0] == '0') {
		sz = {0, n-1};
	} else {
		sz = {1, 0};
	}
	char last = s[0];
	
	ll ans = 0;
	for (int i=1; i<n; i++) {
		if (last == '0') {
			if (s[i] == '0') {
				// 0 -> 0
				sz[0] += i;
				sz[1] += n-i-1; 
			} else {
				// 0 -> 1
				ans = max(ans, sz[0]);
				sz[0] = sz[1] + 1;
				sz[1] = 0;
			}
		} else {
			if (s[i] == '0') {
				// 1 -> 0
				sz[0] += i;
				ans = max(ans, sz[1]);
				sz[1] = n-i-1;
			} else {
				// 1 -> 1
				ans = max(ans, max(sz[0], sz[1]));
				sz[0] = 1;
				sz[1] = 0;
			}
		}
		
		last = s[i];
	}
	
	ans = max(ans, max(sz[0], sz[1]));
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
