#include <bits/stdc++.h>
using namespace std;


using ll = long long;

map<ll, int> memo;
int solve(ll x) {
    if (memo.count(x)) return memo[x];
    if (x < 10) {
        return min(x, 11-x);
    }

    return (memo[x] = min(solve(x / 10) + x%10, solve(x/10+1)+10-x%10));
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;

        cout << solve(n) << '\n';
    }
}


/*
for some optimal payment
for all types of banknotes 10^i, its only possible that
- Alice pays x banknotes 10^i and Bob none;
- or Bob gives x banknotes 10^i and Alice used none to pay.
* this can be trivially proved

consider k the ith digit of the decimal rep. of N
- if Alice uses 10^i banknotes, then she uses k of these banknotes;
- if Bob uses 10^i banknotes, then he uses 10-k+1 of these banknotes;
*/