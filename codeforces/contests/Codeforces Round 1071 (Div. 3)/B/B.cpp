#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*
let s be the sum without removing a k
for any k
	the sum after removing k is equal to
		s - |ak-1 - ak| - |ak+1 - ak| + |ak-1 - ak+1|
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
    	cin >> a[i];
    }
    
	int s = 0;
	for (int i=1; i<n; i++) {
		s += abs(a[i-1] - a[i]);
	}
	
	int ans = s - max(abs(a[0]-a[1]), abs(a[n-2]-a[n-1]));
	for (int k=1; k<n-1; k++) {
		ans = min(ans, s - abs(a[k-1]-a[k]) - abs(a[k]-a[k+1]) + abs(a[k-1]-a[k+1]));
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
