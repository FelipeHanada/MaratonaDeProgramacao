#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int flog2(ll n) { return __builtin_clzll(1) - __builtin_clzll(n); }

map<ll, ll> memo = { { 0, 0 },  { 1, 1 } };
ll solve(ll n) {
    if (memo.count(n)) return memo[n];
    ll h = (1LL << flog2(n));
    return memo[n] = solve(h-1) + (n-h+1) + solve(n-h);
}

int main() {
    ll n; cin >> n;
    cout << solve(n) << '\n';
}

/*
1


01
10
11

001
010
011
*/



