
#include <bits/stdc++.h>
using namespace std;

/*
a range [a, b] contains another range [c, d]
	iff. a <= c and b >= d

we can sort the ranges by min start and max end
and iterate from back to front

this way we guarantee that the ranges seen are the ones that start after the current one
we can maintain the range that ends leftmost, let this be min_r
	therefore, exists a range [c, d] that is contained by [a, b]
		iff. b >= min_r
			(since forall ranges seen c >= a and exists a d <= min_r <= b)
*/

int n;
void solve(const vector<array<int,3>> &a) {
	vector<bool> ans(n);
	int min_r = INT32_MAX;
	for (int i=n-1; i>=0; i--) {
		ans[a[i][2]] = a[i][1]*-1 >= min_r;
		min_r = min(min_r, a[i][1]*-1);
	}
	
	for (int i=0; i<n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
    cin >> n;
    vector<array<int,3>> a(n);
    for (int i=0; i<n; i++) {
    	cin >> a[i][0] >> a[i][1];
    	a[i][1] *= -1;
    	a[i][2] = i;
    }
    
    sort(a.begin(), a.end());
    solve(a);
    
    for (int i=0; i<n; i++) {
    	tie(a[i][0], a[i][1]) = make_tuple(a[i][1]*-1, a[i][0]*-1);
    }
    sort(a.begin(), a.end());
    solve(a);
}