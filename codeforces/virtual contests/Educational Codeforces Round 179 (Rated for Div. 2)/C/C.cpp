#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
    	cin >> a[i];
    }
    
    // we need to compute the 
    vector<int> lw(n+1, 0);
	int last = a[0];
	int size = 1;
    for (int i=1; i<n; i++) {
    	if (a[i] == last) {
    		size++;
    	} else {
    		lw[last] = max(lw[last], size);
    		size = 1;
    	}
    	last = a[i];
    }
    lw[last] = max(lw[last], size);
    
    ll ans = INT64_MAX;
    for (int i=1; i<=n; i++) {
    	if (lw[i])
	    	ans = min(ans, (n - lw[i]) * (ll)i);
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
