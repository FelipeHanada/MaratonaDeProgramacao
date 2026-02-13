#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}


/*
5 10
1 3 2 5 4
-1 -1 -1 -1 -1

1 -> 11
11 - 5 = 6 = 1
*/

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    
    bool ok = true;
    int x = -1;
    for (int i=0; i<n; i++) if (b[i] != -1) {
    	if (x == -1) x = a[i] + b[i];
    	else {
    		if (a[i] + b[i] != x) ok = false;
    	}
    }
    
    int min_a = INT32_MAX, max_a = INT32_MIN;
	for (int i=0; i<n; i++) {
		min_a = min(min_a, a[i]);
		max_a = max(max_a, a[i]);
	}
    
    if (!ok) {
    	cout << "0\n";
    	return;
    }
    
    if (x != -1) {
    	if (min_a + k < x || max_a > x) {
    		cout << "0\n";
    		return;
    	}
    	cout << "1\n";
    	return;
    }
    
    
    // x <= min_a + k
    // x >= max_a   
    cout << min_a + k - max_a + 1 << '\n';
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
