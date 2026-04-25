#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;

        int ans = 0;
        while (1) {
            int old = atoi(s.c_str());
            int _new = 1;
            for (int i=0; i<s.size(); i++) {
                _new *= s[i] - '0';
            }

            if (_new == old) break;
            ans++;
            string t;
            if (_new == 0) t.push_back('0');
            while (_new) {
                t.push_back((_new % 10) + '0');
                _new /= 10;
            }

            s = string(t.rbegin(), t.rend());
        }

        cout << ans << '\n';
    }
}