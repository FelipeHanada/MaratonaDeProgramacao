#include <bits/stdc++.h>
using namespace std;


/*
6 = 110

A xor rev(A) = 110

1011



*/

#define ll long long

ll log2(ll x) {
    return __builtin_clzll(1) - __builtin_clzll(x);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        if (n == 0) {
            cout << "YES\n";
            continue;
        }

        bool palin = false;
        for (int i=log2(n)+1; !palin && i<=63; i++) {
            // verificamos se n é um palindromo
            palin = true;
            for (int j=0; palin && j<i/2; j++) {
                if (!(n&((ll)1<<j)) != !(n&((ll)1<<(i-j-1)))) palin = false;
            }

            if (i % 2 && (n&((ll)1<<(i/2)))) {
                palin = false;
            }
        }

        if (palin) {
            cout << "YES\n";
        } else {
            cout <<"NO\n";
        }
    }
}
