#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    set<int> s;

 	for (int i=0; i<n; i++) {
    	int x;
    	cin >> x;
    	s.insert(x);
    }
    int ans = *lower_bound(s.begin(), s.end(), s.size());
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
