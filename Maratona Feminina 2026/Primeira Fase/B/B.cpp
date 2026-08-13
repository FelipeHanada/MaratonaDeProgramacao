#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    array<ll,26> a, b;
    fill(a.begin(), a.end(), 0);
    fill(b.begin(), b.end(), 0);

    int lasta = -1, lastb = -1;
    string s, t; cin >> s >> t;
    for (char c : s) { a[c - 'a']++; lasta = max(lasta, c - 'a'); };
    for (char c : t) { b[c - 'a']++; lastb = max(lastb, c - 'a'); };
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll k; string s; cin >> k >> s;
            for (char c : s) { a[c - 'a'] += k; lasta = max(lasta, c - 'a'); }
        } else if (t == 2) {
            ll k; string s; cin >> k >> s;
            for (char c : s) { b[c - 'a'] += k; lastb = max(lastb, c - 'a'); }
        } else {
            int result = 0;
            for (int i=0; i<26 && !result; i++) {
                if (lasta == i && lastb == i) {
                    if (a[i] < b[i]) result = 1;
                    else if (a[i] > b[i]) result = 2;
                } else if (lasta == i) {
                    result = 1;
                } else if (lastb == i) {
                    result = 2;
                } else {
                    if (a[i] > b[i]) result = 1;
                    else if (a[i] < b[i]) result = 2;
                }
            }

            if (result == 0) {
                cout << "EMPATE\n";
            } else if (result == 1) {
                cout << "ADA\n";
            } else {
                cout << "PY\n";
            }
        }
    } 
}