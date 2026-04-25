#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; string s;
        cin >> n >> s;
        if (count(s.begin(), s.end(), '0') % 2 == 1) {
            cout << count(s.begin(), s.end(), '0') << '\n';
            for (int i=0; i<n; i++) if (s[i] == '0') {
                cout << i + 1 << ' ';
            }
            cout << '\n';
        } else if (count(s.begin(), s.end(), '1') % 2 == 0) {
            cout << count(s.begin(), s.end(), '1') << '\n';
            for (int i=0; i<n; i++) if (s[i] == '1') {
                cout << i + 1 << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }
}