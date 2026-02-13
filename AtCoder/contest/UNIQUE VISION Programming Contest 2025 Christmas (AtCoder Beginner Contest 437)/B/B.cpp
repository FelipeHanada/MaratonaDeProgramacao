#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i=0; i<h; i++) {
    	for (int j=0; j<w; j++) {
    		cin >> a[i][j];
    	}
    }
    
    unordered_set<int> b;
    for (int i=0; i<n; i++) {
    	int x;
    	cin >> x;
    	b.insert(x);
    }
    
    int ans = 0;
    for (int i=0; i<h; i++) {
    	int curr = 0;
    	for (int j=0; j<w; j++) {
    		curr += b.count(a[i][j]);
    	}
    	ans = max(ans, curr);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();    
    return 0;
}
