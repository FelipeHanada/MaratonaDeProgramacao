#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    deque<bool> saw(26, false);
    for (int i=0; i<n; i++) {
        if (saw[s[i]='a']) {

        }
        saw[s[i]-'a'] = true;
    }   
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}