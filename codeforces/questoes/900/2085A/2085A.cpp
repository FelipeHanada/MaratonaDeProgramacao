#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    // we can do this iff.
    // 1. the word is composed by the same char
    // 2. we cannot make any move and the current solution isnt universal

    deque<char> s(n);
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    map<char, int> ocurr;
    for (char c : s) {
        ocurr[c]++;
    }

    if (ocurr.size() == 1) {
        cout << "NO\n";
        return;
    }

    bool minimum = false;
    while (s.size() > 1) {
        if (s.front() < s.back()) {
            minimum = true;
            break;
        } else if (s.front() > s.back()) {
            minimum = false;
            break;
        } else {
            s.pop_front();
            s.pop_back();
        }
    }

    if (minimum || k > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}