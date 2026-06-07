#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int x = s[0]-'a';
        if (x < 3) cout << 2;
        else if (x < 6) cout << 3;
        else if (x < 9) cout << 4;
        else if (x < 12) cout << 5;
        else if (x < 15) cout << 6;
        else if (x < 19) cout << 7;
        else if (x < 22) cout << 8;
        else cout << 9;
    }
    cout << '\n';
}
