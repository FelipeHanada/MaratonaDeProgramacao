#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*

let g(x) = a_1 xor a_2 ... xor a_x
	and g(0) = 0
then f(x, y) = g(y) xor g(y-1) (y - x > 0)
	f(x, y) = 0 iff. g(y)  = g(x-1) (if x != y)
				  or g(x) != 0      (if x = y)


then we satisfy the conditions
	if we can make g(i) != g(j) for every pair i, j except i=x and j=y
		and g(i) != 0

by definition g(i) = a[i] xor g(i-1)

lets construct a vector a such that
	g(i) = i forall i != y
	and g(y) = g(x - 1)
*/

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> ans(n+1);
	for (int i=1; i<r; i++) cout << (i^(i-1)) << ' ';
	cout << ((l-1)^(r-1)) << ' ';
	if (r < n) cout << ((r+1)^(l-1)) << ' ';
	for (int i=r+2; i<=n; i++) cout << (i^(i-1)) << ' ';
    cout << '\n';
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
