#include <bits/stdc++.h>
using namespace std;


/*

every valid solution is such that
	(S is the set of reindeers pulling the sled)

	sum(i in S) p[i] >= sum(i not in S) w[i]
	
	sum(i in S) p[i]+w[i] >= sum w[i]
	
since we want to minimize the number of deers in S
	and sum w[i] is constant, we can greedily choose
	what reindeers will be in S by ordering by p[i]+w[i]
*/

#define ll long long

bool cmp(array<int, 2> &a, array<int, 2> &b) {
	return a[0]+a[1] < b[0]+b[1];
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<array<int, 2>> a(n);
		ll sumW = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i][0] >> a[i][1];
			sumW += a[i][0];
		}
		sort(a.begin(), a.end(), cmp);
		reverse(a.begin(), a.end());
		
		int ans = n;
		ll curr = 0;
		for (int i=0; i<n && curr < sumW; i++) {
			curr += a[i][0] + a[i][1];
			ans--;
		}
		cout << ans << '\n';
	}
}
