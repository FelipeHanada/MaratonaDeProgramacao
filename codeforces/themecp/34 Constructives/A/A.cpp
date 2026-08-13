#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n; string s, t;
        cin >> n >> s >> t;

        bool ok = 1;
        int last = 0;
        int cs = 0, ct = 0;
        for (int i=0; i<n; i++) {
            if (i % 2 == 0 && (cs == i/2 || ct == i/2)) {
                bool x = 1, y = 1;
                for (int j=last; j < i; j++) {
                    if (s[j] != t[j]) x = 0;
                }
                for (int j=last; j < i; j++) {
                    if (s[j] == t[j]) y = 0;
                }

                if (!x && !y) ok = 0;
                last = i;
            }

            cs += (s[i] == '1');
            ct += (t[i] == '1');
        }
        if (n % 2 == 0 && (cs == n/2 || ct == n/2)) {
            bool x = 1, y = 1;
            for (int j=last; j < n; j++) {
                if (s[j] != t[j]) x = 0;
            }
            for (int j=last; j < n; j++) {
                if (s[j] == t[j]) y = 0;
            }

            if (!x && !y) ok = 0;
            last = n;
        }

        for (int j=last; j<n; j++) {
            if (s[j] != t[j]) ok = 0;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
