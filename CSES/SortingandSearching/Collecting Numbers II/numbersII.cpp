#include <bits/stdc++.h>
using namespace std;


/*
some number x contributes with  the cost (+1) iff. x+1 ocurrs before y in the array

after some change i, j the following can ocurr
	let x = a[i], y = a[j]
*/

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), p(n+1);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	
	int ans = 1;
	for (int i=1; i<n; i++) {
		if (p[i+1] < p[i]) ans++;
	}
	
	while (m--) {
		int i, j;
		cin >> i >> j;
		i--; j--;
		if (a[i] > a[j]) swap(i, j);
		
		ans -= (a[i]<n && p[a[i]+1]<p[a[i]]) + (a[i]>1 && p[a[i]]<p[a[i]-1]);
		ans -= (a[j]<n && p[a[j]+1]<p[a[j]]) + (a[j]>1 && a[i]+1<a[j] && p[a[j]]<p[a[j]-1]);
						
		swap(p[a[i]], p[a[j]]);
		swap(a[i], a[j]);
		swap(i, j);
		
		ans += (a[i]<n && p[a[i]+1]<p[a[i]]) + (a[i]>1 && p[a[i]]<p[a[i]-1]);
		ans += (a[j]<n && p[a[j]+1]<p[a[j]]) + (a[j]>1 && a[i]+1<a[j] && p[a[j]]<p[a[j]-1]);

		cout << ans << '\n';
	}
}
