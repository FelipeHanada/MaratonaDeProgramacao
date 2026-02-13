#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	
	vector<int> p(n+1);
	for (int i=0; i<n; i++) p[a[i]] = i;
	
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		l--; r--;
		
		if (p[k] > r || p[k] < l) {
			cout << "-1 ";
			continue;
		}
		
		int le = 0, gr = 0;
		int le_need = 0, gr_need = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] == k) break;
			if (p[k] > mid) {
				// a[mid] must be lower than k
				le++;
				le_need += (a[mid] > k);
				l = mid + 1;
			} else {
				// a[mid] must be greater than k
				gr++;
				gr_need += (a[mid] < k);
				r = mid - 1;
			}
		}
		
		if (gr > n - k || le >= k) {
			cout << "-1 ";
			continue;
		}
		
		int ans = 2 * max(le_need, gr_need);
		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
