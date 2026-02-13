#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 5e5;
constexpr int MOD = 998244353;
int n;
int c[26];
int dp[MAX_N+1];

int fac[MAX_N+1];
int prod;

int inv(int x) {
	return x <= 1 ? x : MOD - (ll)(MOD/x) * inv(MOD%x) % MOD;
}

int main() {
	fac[0] = 1;
	for (int i=1; i<=MAX_N; i++) {
		fac[i] = ((ll)fac[i-1] * i) % MOD;
	}

	int tt;
	cin >> tt;
	while (tt--) {
		n = 0;
		for (int i=0; i<26; i++) {
			cin >> c[i];
			n += c[i];
		}
		
		fill_n(dp, n+1, 0);
		dp[0] = 1;
		prod = 1;
		for (int i=0; i<26; i++) {
			if (!c[i]) continue;
			for (int j=n; j>=c[i]; j--) {
				dp[j] = ((ll)dp[j] + dp[j-c[i]]) % MOD;
			}
			prod = ((ll)prod * fac[c[i]]) % MOD;
		}
		
		int a = ((ll)fac[n/2] * fac[(n+1)/2]) % MOD;
		int b = ((ll)a * inv(prod)) % MOD;
		cout << ((ll)dp[(n+1)/2] * b) % MOD << '\n';
	}
}
