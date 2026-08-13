#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    ll g = 0;
    for (int i=0; i<n-1; i++) g = __gcd(g, abs(a[i] - a[i+1]));

    ll a0;
    if (g == 0) {
        a0 = a[0];
    } else {
        // a0 is the smallest positive of the form a[0] + 2 * g * k
        // a[0]+2*g*k > 0
        // k > -a[0]/(2*g)
        // k = floor(-a[0]/(2*g)) + 1
        // k = (-a[0] - 2*g + 1)/(2*g) + 1
        ll k = (-a[0] - 2*g + 1)/(2*g) + 1;
        a0 = a[0] + 2*g*k;
    }

    ll an = a0;
    for (int i=0; i<n-1; i++) {
        an += abs(a[i] - a[i + 1]);
    }

    cout << an << '\n';
}


/*
consider an operation on i
for every index j modified
    a[j] = 2a[i] - a[j] => we make a[i] - a[j] become a[j] - a[i]

then, for every i in the decreased version of the array a', we have
    abs(a[i] - a[i+1]) = abs(a'[i] - a'[i+1])


minimizing a[1] we minimize a[n]
    we need to find the smallest positive a1 that we can get
    (since at the end, a must be positive and non-decreasing, a[1] > 0 suffices)

an operation on i
    changes a1 by adding or subtracting 2 * delta

2 * delta = 2 * g * k
    where g = gcd(deltas) and k is an integer


*/