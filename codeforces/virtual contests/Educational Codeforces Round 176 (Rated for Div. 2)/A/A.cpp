#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, k;
    cin >> n >> k;
    // if n is even -> n - x is also even
    // if n is odd -> n - x is even
    int ans = 0;
    if (n % 2) {
		n -= k/2*2 + k%2;
		ans++;
	}

	if (n) {
		ans += n/(k/2*2);
		if (n % (k/2*2)) {
			ans++;
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
