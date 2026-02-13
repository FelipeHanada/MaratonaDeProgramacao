#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

int get_ub(vector<ll>& a, int x) {
	int l=0, r=a.size();
	
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (x < a[mid]) {
			r = mid;
		} else {
			l = mid;
		}
	}
	
	return r;
}	


constexpr ll MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int j=0; j<m; j++) cin >> b[j];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> pre_b(m+1);
    
    pre_b[0] = 0;
    for (int j=1; j<=m; j++) pre_b[j] = (pre_b[j-1] + b[j-1]) % MOD;
    
    ll ans = 0;
    int ub = 0;
    for (int i=0; i<n; i++) {
    	while (ub < m && b[ub] <= a[i]) ub++;
    	
    	// [....] [ub ....]
    	ll left = (((a[i]*ub)%MOD) - pre_b[ub]) % MOD;
    	ll right = (((pre_b[m] - pre_b[ub])%MOD) - ((a[i]*(m-ub))%MOD)) % MOD;
    	
    	ans = (((ans + left)%MOD) + right) % MOD;
    }
    
    cout << ((ans % MOD) + MOD) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();    
    return 0;
}
