#include <bits/stdc++.h>
using namespace std;

#define  ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, x;
        cin >> n >> m >> x;
        ll i, j;
        i = (x-1) % n;
        j = (x-1) / n;

        cout << i * m + j + 1 << '\n';
    }
}