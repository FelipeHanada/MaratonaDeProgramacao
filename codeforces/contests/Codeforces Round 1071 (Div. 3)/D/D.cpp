#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
n = 3
111 -> +3
011 -> +2
001 -> +1
101 -> +1
000
... => 7


n = 4
1111
0111
0011
0001


1111
0111
0011
1011 <---
*/

void precompute() {

}


void solve() {
	int n;
	cin >> n;
	
	map<int, vector<int>> s;
	for (int i=0; i<(1<<n); i++) {
		s[~i & (i + 1)].push_back(i);
	}
	
	for (auto it = s.rbegin(); it!=s.rend(); it++) {
		for (int x : it->second) {
			cout << x << ' ';
		}
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
