#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    deque<int> m(26, 0);
    for (int i=0; i<n; i++) m[s[i] - 'a']++;
    for (int i=0; i<n; i++) m[t[i] - 'a']--;

    for (int i=0; i<26; i++) {
        if (m[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}