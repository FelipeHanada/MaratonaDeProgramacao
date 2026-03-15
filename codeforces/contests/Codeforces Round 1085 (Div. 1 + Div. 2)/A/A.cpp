#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n; string s;
        cin >> n >> s;
        int ans1 = count(s.begin(), s.end(), '1');
        for (int i=1; i<n-1; i++) {
            if (s[i-1] == s[i+1] && s[i-1] == '1' && s[i] == '0') {
                ans1++;
                s[i] = '1';
            }
        }
        int ans2 = ans1;
        for (int i=1; i<n-1; i++) {
            if (s[i-1] == s[i+1] && s[i-1] == '1' && s[i] == '1') {
                ans2--;
                s[i] = '0';
            }
        }

        cout << ans2 << ' ' << ans1 << '\n';
    }
}