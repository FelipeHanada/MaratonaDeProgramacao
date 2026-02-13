#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) cin >> c[i];
    
    ll is = 0;
    for (int i=0; i<n; i++) {
    	bool ok = true;
    	for (int j=0; j<n && ok; j++) {
    		if (a[j] >= b[(i+j)%n]) ok = false;
    	}
    	is += ok;
    }
    
    ll js = 0;
    for (int i=0; i<n; i++) {
    	bool ok = true;
    	for (int j=0; j<n && ok; j++) {
    		if (b[j] >= c[(i+j)%n]) ok = false;
    	}
		js += ok;
    }
    
    cout << n * is * js << '\n';
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
