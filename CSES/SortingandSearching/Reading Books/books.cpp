#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    ll big = 0;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        sum += x;
        big = max(big, x);
    }

    if (big >= sum / 2) {
        cout << 2 * big << '\n';
    } else {
        cout << sum << '\n';
    }
}
