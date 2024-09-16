#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
#define MOD (int) (1e9 + 7)

ll bpow(int a, int b) {
    ll r = 1;
    ll i = a;

    while (b > 0) {
        if (b & 1) r = (r * i) % MOD;

        b >>= 1;
        i = (i * i) % MOD;
    }

    return r;
}


int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        cout << bpow(a, b) << endl;
    }
}