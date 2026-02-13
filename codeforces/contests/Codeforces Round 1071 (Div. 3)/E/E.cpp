#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*

3 5 5
0 1 0
2 4 3

min_a[] = 2 2 4
max_a[] = 2 3 6

min_b[] = 0 3 3
max_b[] = 0 4 5

we can compute the minimum and the maximum number of voters necessary to make this arrangement

if X win a district i, there must be at least p[i]/2+1 voters of X allocated for that district
									and at most p[i]-p[i]/2+1 voters of Y


4 23 20
1111
2 2 2 2

min_a[] = 2 4 6 8
max_a[] = 2 4 6 8

min_b[] = 0 0 0 0
max_b[] = 0 0 0 0		
*/

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	vector<ll> p(n);
	for (int i=0; i<n; i++) cin >> p[i];
	
	ll min_a, min_b, max_a, max_b;
	min_a = min_b = 0;
	
	int win_a=0;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			win_a++;
			min_a += p[i]/2 + 1;
		} else {
			win_a--;
			min_b += p[i]/2 + 1;
		}
	}
	
	ll sum_p = 0;
	for (int i=0; i<n; i++) sum_p += p[i];
	
	if (abs(win_a) == n) {
		if ((win_a > 0 && x-win_a < y) || (win_a<0 && y+win_a < x)) {
			cout << "NO\n";
			return;
		}
	}
	
	cout << ((x + y >= sum_p && x >= min_a && y >= min_b) ? "YES" : "NO") << '\n';
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
