#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for (int i=0; i<n; i++) cin >> p[i];
   	
    set<int> s;
    for (int q=0; q<n; q++) {
    	int d;
    	cin >> d;
    
    	int curr = d - 1;
    	while (!s.count(curr)) {
    		s.insert(curr);
    		curr = p[curr] - 1;
    	}

    	cout << s.size() << ' ';
    }
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
