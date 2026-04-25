#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; string s;
        cin >> n >> s;

        bool ok = 1;
        if (n % 2) {
            if (s.front() == 'b') ok = 0;
            for (int i=1; ok && i<n; i+=2) {
                if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
                    ok = 0;
                }
            }
        } else {
            for (int i=0; ok && i<n; i+=2) {
                if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
                    ok = 0;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
