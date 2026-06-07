#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


string ans4[] = {
    "++**",
    "+*+*",
    "++++",
    "+**+"
};

void solve(ll line, ll n, bool reverse = 0, bool flipped = 0) {
    if (n == 4) {
        const string &s = ans4[line];

        for (ll i=0; i<n; i++) {
            ll j = i;
            if (reverse) j = n-i-1;
            char c = s[j];
            if (flipped) c = (c == '+' ? '*' : '+');
            cout << c;
        }
        return;
    }

    if (line < n / 2) {
        // prints A' mirrored and then A
        solve(line, n/2, reverse, flipped);
        solve(line, n/2, reverse, flipped);
    } else {
        // prints A mirrored and then A'
        solve(line-n/2, n/2, reverse, flipped);
        solve(line-n/2, n/2, reverse, !flipped);
    }
}

void test() {
    ll n;
    cin >> n;
    vector<string> a(n);
    for (ll i=0; i<n; i++) {
        cin >> a[i];
    }

    for (ll i=0; i<n; i++) {
        for (ll j=i+1; j<n; j++) {
            ll prod = 0;
            for (ll k=0; k<n; k++) {
                prod += (a[i][k] == a[i][j] ? 1 : -1);
            }

            if (prod != 0) {
                cout << i << ' ' << j << '\n';
            }
        }
    }
}

void mmain() {_
    ll n;
    cin >> n; n = (1 << n);

    if (n == 1) {
        cout << "+\n";
    } else if (n == 2) {
        cout << "++\n";
        cout << "*+\n";
    } else {
        for (ll i=0; i<n; i++) {
            // cout << i << ": ";
            solve(i, n);
            cout << '\n';
        }
    }
}


int main() {
    mmain();
    // test();
}
