#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

constexpr int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i=0; i<n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    
    while (m--) {
		int t; ll x;
		cin >> t >> x;
		if (t == 1) {
		} else if (t == 2) {
		} else {
		}
    }
    
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
