#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

constexpr int N = 60;
array<array<ull, N+1>, N+1> dp;
// ull dp[N+1][N+1]; // dp[i][j] = cost to make i shifts on x and j shifts of y
void precompute() {
	array<array<ull, N+1>, N+1> prox;
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=N; j++) {
			dp[i][j] = INT64_MAX;
			prox[i][j] = INT64_MAX;
		}
	}
	dp[0][0] = prox[0][0] = 0;
	for (ull k=1; k<=N; k++) {
		for (ull i=N; i>=k; i--) {
			for (ull j=0; j<=N; j++) {
				if (dp[i-k][j] != INT64_MAX) {
					prox[i][j] = prox[j][i] = min(dp[i][j], dp[i-k][j] + (ull)1<<k);
				}
			}
		}

		swap(dp, prox);
	}
}

ull flog2(ull n) {
	return __builtin_clzll(1) - __builtin_clzll(n);
}

void solve() {
    
/*
6 2
110 -> 2 | >=3x
010 -> 1 | >=2
*/

	ull x, y;
	cin >> x >> y;

	if (x > y) swap(x, y);

	int i, j;
	ull ans = INT64_MAX;
	if (x == 0) {
		i = 0;
		j = (y ? flog2(y) + 1 : 0);
	} else {
		i = flog2(x), j = flog2(y);
		while (i >= 0 && j >= 0 && (bool)(x&((ull)1<<i)) == (bool)(y&((ull)1<<j))) {
			i--; j--;
		}
		i++; j++;

		while (i <= flog2(x)) {
			ans = min(ans, dp[i][j]);
			i++; j++;
		}
	}
	
	for (int i2=i; i2<=N; i2++) {
		for (int j2=j; j2<=N; j2++) {
			ans = min(ans, dp[i2][j2]);
		}
	}
	
	cout << ans << '\n';
	// each 
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
