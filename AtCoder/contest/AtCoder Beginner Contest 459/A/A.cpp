#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

int main() {
    string s = "HelloWorld";
    int x;
    cin >> x;
    x--;
    for (int i=0; i<s.size(); i++) if (i != x) {
        cout << s[i];
    }
    cout << '\n';
}
