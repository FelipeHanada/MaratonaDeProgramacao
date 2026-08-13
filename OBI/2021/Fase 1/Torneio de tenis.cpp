#include <bits/stdc++.h>
using namespace std;


int main() {
    int n = 0;
    for (int i=0; i<6; i++) {
        string s;
        cin >> s;
        if (s == "V") n++;
    }

    if (n >= 5) cout << 1;
    else if (n >= 3) cout << 2;
    else if (n >= 1) cout << 3;
    else cout << -1;
    cout << '\n';   
}