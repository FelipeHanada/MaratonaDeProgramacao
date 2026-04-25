#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        int c1 = 0, c2 = 0;
        for (int i=0; i<n-1; i++) {
            if (s[i] == '(' && s[i+1] == '(') c1++;
            if (t[i] == '(' && t[i+1] == '(') c2++;
        }

        stack<char> stk;
        int d1 = 0, d2 = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') stk.push('(');
            else stk.pop();
            if (stk.empty()) d1++;
        }
        for (int i=0; i<n; i++) {
            if (t[i] == '(') stk.push('(');
            else stk.pop();
            if (stk.empty()) d2++;
        }

        if (c1 != c2 || (min(d1, d2) == 1 && max(d1, d2) > 1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
