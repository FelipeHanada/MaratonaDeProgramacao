#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*
an element can be painter last iff.
1. it is the first elemnt
2. it is the alst element
3. there are two elements painted before and after him

ans = max(
	first + max sum of k elm. from second,
	last + max sum of k elm. from first to n-1,
	a[i] + max sum of k elm.
)
*/
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
    	cin >> a[i];
    }
    
    ll ans;
    multiset<int> left, right;
    ll sum = 0;
    for (int i=0; i<n-1; i++) {
    	right.insert(a[i]);
    }
    auto it = right.rbegin();
    for (int i=0; i<k; i++) {
    	sum += *(it++);
    }
   	ans = sum + a[n-1];
    right.insert(a[n-1]);
    right.extract(a[0]);
    sum = 0;
    it = right.rbegin();
    for (int i=0; i<k; i++) {
    	sum += *(it++);
    }
    ans = max(ans, sum + a[0]);
	left.insert(a[0]);
    
	if (k > 1) {
    	for (int i=1; i<n-1; i++) {
    		right.extract(a[i]);
    		
    		// compute max sum that uses atleast one element from each set
    		auto itl = left.rbegin(), itr = right.rbegin();
    		sum = *(itl++) + *(itr++);
    		
    		for (int j=2; j<k; j++) {
    			if (itl == left.rend()) {
    				sum += *(itr++);
    			} else if (itr == right.rend() || *(itl) > *(itr)) {
    				sum += *(itl++);
    			} else {
    				sum += *(itr++);
    			}
    		}
    	
    		ans = max(ans, sum + a[i]);
    		left.insert(a[i]);
    	}
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
