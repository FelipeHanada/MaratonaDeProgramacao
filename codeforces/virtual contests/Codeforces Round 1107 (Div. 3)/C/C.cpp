#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; string s;
        cin >> n >> s;
        
        int seg = 0;
        char last = -1;
        for (int i=0; i<n; i++) {
            if (last != s[i]) seg++;
            last = s[i];
        }

        if (seg == 2) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
}

/*
101 => 0

...111000... => 2

...111...000...111... => 1


111000111000 => 


*/
