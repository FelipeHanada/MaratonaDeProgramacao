#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*
7
5 11 22 74 52 97 82


make all 0's or make all min(a)
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int ans = a[0];
    int alt = INT32_MAX;
    for (int i=1; i<n; i++) {
		// max value that can turn a[i] into a[0]
		// a[i] mod x = a[0], since x is maximum
		// x = a[i] - a[0];
		alt = min(alt, a[i] - a[0]);
    }
    
    cout << max(ans, alt) << '\n';
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
