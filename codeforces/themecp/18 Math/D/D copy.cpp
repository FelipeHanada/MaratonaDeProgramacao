#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    string s, t;
    cin >> s >> t;
    int n = max(s.size(), t.size()) + 3;
    
    vector<int> a(n, 0), b(n, 0);
    for (int i=0; i<s.size(); i++) {
        a[s.size()-i-1] = (s[i] == '1');
    }
    for (int i=0; i<t.size(); i++) {
        b[t.size()-i-1] = (t[i] == '1');
    }

    vector<int> to_check(n-2);
    iota(to_check.begin(), to_check.end(), 0);
    reverse(to_check.begin(), to_check.end());
    while (!to_check.empty()) {
        vector<int> next;
        for (int x : to_check) {
            if (a[x] && a[x+1]) {
                a[x] = 0;
                a[x+1] = 0;
                a[x+2] = 1;
                next.push_back(x+2);
            }
        }
        to_check = next;
    }

    to_check.assign(n-2, 0);
    iota(to_check.begin(), to_check.end(), 0);
    reverse(to_check.begin(), to_check.end());
    while (!to_check.empty()) {
        vector<int> next;
        for (int x : to_check) {
            if (b[x] && b[x+1]) {
                b[x] = 0;
                b[x+1] = 0;
                b[x+2] = 1;
                next.push_back(x+2);
            }
        }
        to_check = next;
    }

    for (int i=n-1; i>=0; i--) {
        if (a[i] > b[i]) {
            cout << ">\n";
            return 0;
        } else if (a[i] < b[i]) {
            cout << "<\n";
            return 0;
        }
    }

    cout << "=\n";
}