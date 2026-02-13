#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
x y x y x y x y ... 

x = n / 2
y = (n + 1) / 2

we need to partitionate the chars such that
	sum(i \in X) c[i] = n/2
	sum(i \in Y) c[i] = (n+1)/2

ans := 0
for any partition that satisfies it
	ans := ans + (x!/prod(i \in X)c[i]!) * (y!/prod(i \in Y)c[i]!)


*/


constexpr int MOD = 998244353;
constexpr int inv2 = 499122177;

// constexpr int MAX_C = 5e5;
// int fac[MAX_C+5];
void precompute() {
    // fac[0] = 1;
    // for (int i=1; i<MAX_C+5; i++) {
    //     fac[i] = ((ll)fac[i-1] * i) % MOD;
    // }
}

int inv(int a) {
    return a <= 1 ? a : MOD - (ll)(MOD/a) * inv(MOD % a) % MOD;
}

constexpr int NMASK = 1<<26;
int dp[NMASK];
// ll prod[NMASK];
void solve() {
    int n = 0;
    int cnt = 0;
    vector<int> c;
    for (int i=0; i<26; i++) {
    	int x;
        cin >> x;
        if (x) {
            n++;
            cnt += x;
            c.push_back(x);
        }
    }
    sort(c.begin(), c.end());
    unordered_map<int, int> fac;
    {
        int i=0;
        int f = 1;
        for (int j=1; j<=max(c.back(), cnt-cnt/2); j++) {
            f = ((ll)f * j) % MOD;
            if (j == c[i] || j == cnt/2 || j == cnt-cnt/2) {
                fac[j] = f;
                while (i < n && c[i] == j) i++; 
            }
        }
    }
    
    fill_n(dp, (1<<n), 0);
    // fill_n(prod, (1<<n), 1);
    // { curr_x, prod c[i] }
    int ans = 0;
    for (int x=1; x<(1<<n); x++) {
    	int j;
    	for (j=0; !(x&(1<<j)); j++);
    	dp[x] = dp[x&~(1<<j)] + c[j];
        // prod[i] = (prod[i&~(1<<j)] * inv(fac[c[j]])) % MOD;
    	
        int x1 = x;
        int y1 = ((1<<n)-1) & ~x;
        if (y1 <= x && dp[y1] == cnt/2) swap(x1, y1);
        if (y1 <= x && dp[x1] == cnt/2) {
            ll left = fac[cnt/2];
            // int y = ((1<<n)-1) & ~x;
            int right = fac[cnt-cnt/2];

            for (int j=0; j<n; j++) {
                if (x1|(1<<j)) left = ((ll)left * inv(fac[c[j]])) % MOD;
                else right = ((ll)right * inv(fac[c[j]])) % MOD;
            }

            ans = (ans + ((ll)left * right) % MOD) % MOD;
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
