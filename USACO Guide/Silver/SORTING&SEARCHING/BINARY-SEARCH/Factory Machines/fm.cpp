#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MAX_N = 2e5;
int n, t;
int k[MAX_N];

bool check(ll T) {
    // quantidade de tempo
    ll prod = t;
    for (int i=0; i<n && prod > 0; i++) {
        prod -= T / (ll)k[i]; // quantidade produzida pela máquina i
    }

    return prod <= 0;
}

int main() {
    cin >> n >> t;

    for (int i=0; i<n; i++) {
        cin >> k[i];
    }

    ll l = 1, r = 1, mid;

    while (!check(r)) {
        r <<= 1;
    }

    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
}
