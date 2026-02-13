#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*
9 5
3 5 2 3 3 5 8 1 2
4 6 2 4 6

0 1 2 3 4 5 6 7 8
3 5 2 3 3 5 8 1 2
4 6 2 4 6

menor indice após consumir o b[i]

4 -> (2, 0)
6 -> (7, min(2, 7))
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) {
    	cin >> a[i];
    }
    for (int i=0; i<m; i++) {
    	cin >> b[i];
    }

    vector<pair<int, int>> b_s;
    int l=0, r=0;
    while (l<n && r<m) {
    	if (a[l] >= b[r]) {
    		b_s.push_back({b[r], r});
    		r++;
    	}
    	l++;
    }
        	
    if (r == m) {
    	cout << "0\n";
    	return;
    }
    
    b_s.push_back({b[r], r});
    sort(b_s.begin(), b_s.end());
    
    int ans = INT32_MAX;
    for (auto [bi, skip] : b_s) {
    	l=0; r=0;
    	while (l<n && r<m) {
    		if (r == skip) {
    			r++;
    		} else {
	    		if (a[l] >= b[r]) r++;
    			l++;
			}
    	}
    	
    	if (r == m) {
			ans = bi;
			break;
    	}
    }
    
    if (ans == INT32_MAX) {
    	cout << "-1\n";
    	return;
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
