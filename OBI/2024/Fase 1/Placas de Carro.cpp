#include <bits/stdc++.h>
using namespace std;


inline bool d(char c) { return c >= '0' && c <= '9'; }
inline bool l(char c) { return c >= 'a' && c <= 'z'; }
inline bool L(char c) { return c >= 'A' && c <= 'Z'; }

int main() {
    string s;
    cin >> s;

    if (s.size() == 8 && L(s[0]) && L(s[1]) && L(s[2]) && s[3] == '-' && d(s[4]) && d(s[5]) && d(s[6]) && d(s[7])) {
        cout << 1 << '\n';
    } else if (s.size() == 7 && L(s[0]) && L(s[1]) && L(s[2]) && d(s[3]) && L(s[4]) && d(s[5]) && d(s[6])) {
        cout << 2 << '\n';
    } else {
        cout << 0 << '\n';
    }
}