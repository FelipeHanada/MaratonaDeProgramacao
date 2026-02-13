#include <bits/stdc++.h>
using namespace std;

#define ll long long


constexpr int MAX_N = 11;
int fib[MAX_N+1];
void precompute() {
	fib[0] = 1;
	fib[1] = 1;
	for (int i=2; i<=MAX_N; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
}

// 1 1 2 3 5 8

void solve() {
    int n, m;
    cin >> n >> m;
    string ans;
    for (int i=0; i<m; i++) {
    	int w, l, h;
    	cin >> w >> l >> h;
    	if (w > l) swap(w, l);
    	
		// tem que caber o maior e o segundo maior um em cima do outro
		// ou o maior e o segundo maior um do lado do outro
		if ((w >= fib[n] && h >= fib[n+1]) || (w >= fib[n] && l >= fib[n+1] && h >= fib[n])) {
			ans.push_back('1');
		} else {
			ans.push_back('0');
		}
    }
    
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
