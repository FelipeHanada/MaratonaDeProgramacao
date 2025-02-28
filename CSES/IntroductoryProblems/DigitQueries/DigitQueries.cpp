#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve(ll k) {
    k--;  // turns 0-indexed

    int i = 2;
    ll d = 10;
    ll sum = 9;
    while (sum <= k) {
        k -= sum;
        sum = 9 * d * i;
        i++; d *= 10;
    }
    i--;

    d = i;
    for (int j=i-1; j>0; j--) {
        if (k % i == j)
            return (k / d) % 10;
        d *= 10;
    }

    return k / d + 1;
}

int main() {
    int n;
    cin >> n;
    
    ll k;
    for (int i=0; i<n; i++) {
        cin >> k;
        cout << solve(k) << "\n";
    }
}