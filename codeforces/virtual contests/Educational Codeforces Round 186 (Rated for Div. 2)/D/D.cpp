#include <bits/stdc++.h>
using namespace std;

#define ll long long


constexpr int MOD = 998244353;


/*
what qualifies a fair permutation p?
- there are exactly T = sum(a[i]) rounds
- the ith person chooses T/n + (T%n>i)
- if T/n+(T%n>i) < a[j] : such that p[i] = j
	then p is not a fair permutation
	

4
6 | 1 4 2 1
T = 14
c[] = 4 4 3 3

quest: how many permutations satisfies
	a[p[i]] <= c[i] for all i

*/

constexpr int MAX_N = 50;
ll pow2[MAX_N+1];
ll fac[MAX_N+1];
void precompute() {
	pow2[0] = 1;
	fac[0] = 1;
	for (int i=1; i<=MAX_N; i++) {
		pow2[i] = (2 * pow2[i-1]) % MOD;
		fac[i] = (i * fac[i-1]) % MOD;
	}
}

map<pair<ll, ll>, ll> memo;
ll comb(ll n, ll k) {
	if (n <= 1 || k == 0 || k == n) return 1;
	
	if (memo.count({n, k})) return memo[{n, k}];
	
	ll ans = (comb(n-1, k-1) + comb(n-1, k)) % MOD;
	memo[{n, k}] = ans;
	return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    ll sum = 0;
    for (int i=0; i<=n; i++) {
    	cin >> a[i];
    	sum += a[i];
    }
    
    ll r = sum/n;
    ll g = sum%n;
    if (g == 0) {
    	int gr = 0, leq = 0;
    	for (int i=1; i<=n; i++) {
    		if (a[i] > r) {
    			gr++;
    		} else {
    			leq++;
    		}
    	}
    	
    	if (gr) {
    		cout << "0\n";
    		return;
    	}
    	
    	cout << fac[leq] << '\n';
    
    } else {
    	// there is something like k+1 k+1 ... k k k k
    	int gr = 0, eq = 0, le = 0;
    	for (int i=1; i<=n; i++) {
    		if (a[i] > r+1) {
    			gr++;
    		} else if (a[i] < r+1) {
    			le++;
    		} else {
    			eq++;
    		}
    	}
    	
    	if (gr || eq > g) {
    		cout << "0\n";
    		return;
    	}
    	
    	// ans = comb(g, eq) * eq! * le!
    	//     = g!/eq!(g-eq)!
    	cout << ((comb(g, eq) * fac[eq]) % MOD * fac[le]) % MOD << '\n';
	}
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
