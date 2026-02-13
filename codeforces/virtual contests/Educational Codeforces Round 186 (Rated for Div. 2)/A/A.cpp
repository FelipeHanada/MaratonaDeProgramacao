#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 1, b = 0;
    for (int i=0; i+3<n; i++) {
    	int c = 0;
    	if (s[i] == '2') c++;
    	if (s[i+1] == '0') c++;
    	if (s[i+2] == '2') c++;
    	if (c == 3) {
    		if (s[i+3] == '5') {
    			b++;
    		} else if (s[i+3] == '6') {
    			a = 0;
    		}
    	}
    }
    
    cout << min(a, b) << '\n';
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
