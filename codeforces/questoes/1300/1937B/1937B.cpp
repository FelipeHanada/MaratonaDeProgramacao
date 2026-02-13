#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    deque<char> ans;
    ans.push_back(s1[0]);
    int c1 = 1, c2 = 0;
    // X  c1 Y
    // c2 Y
    /*
    110
    010
    */
    for (int i=0; i<n-1; i++) {
        if (s1[i+1] == s2[i]) {
            c2 += c1;
            ans.push_back(s1[i+1]);
        } else if (s1[i+1] == '0' && c1) {
            c2 = 0;
            ans.push_back(s1[i+1]);
        } else {
            c2 += c1;
            c1 = 0;
            ans.push_back(s2[i]);
        }
    }

    ans.push_back(s2[n-1]);
    
    for (char c : ans) {
        cout << c;
    }
    cout << '\n';
    cout << c1 + c2 << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
