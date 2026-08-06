#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    //at most k flipped llervals
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll i=0; i<n; i++) cin >> a[i] >> b[i];

    vector<ll> dp(n+1);
    dp[0] = 0;
    for (ll i=1; i<=n; i++) dp[i] = dp[i-1] + a[i-1];

    while (k--) {
        vector<ll> next(n+1); next = dp;
        ll curr = 0, best = 0;
        for (ll i=1; i<=n; i++) {
            curr = max(dp[i-1] + a[i-1], curr + b[i-1]);
            // nao flipar nada, extender
            // curr = max(curr, dp[i-1] + b[i-1]); // criar um novo seg

            best = max(curr, best + a[i-1]);

            next[i] = best;
        }
        swap(next, dp);
    }

    cout << dp[n] << '\n';
}


/*

0 2  8 11 20 24 31 36
0 2 11 16 20 28 32 38 
     X
     X  X

opções:
1. aumentar o segmento atual flipado
2. criar um novo segmento flipado
3. 

X X X X
        _


dp[k][i] = best answer where the last llerval changed ended atleast at i
            and there was k llerval changes

dp[k][i] = max(
    dp[k-1][j] + best change on the llerval [j+1, i]
    forall j < i
)
we want to make this computation fast.

dp[k] is monotonic, its always optimal to choose the bigger i to maximize dp[k][i]
a kadane strategy may work




*/

