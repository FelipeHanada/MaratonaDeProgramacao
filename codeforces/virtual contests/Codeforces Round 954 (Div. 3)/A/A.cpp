#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        int a1 = abs(x2-x1)+abs(x3-x1),
            a2 = abs(x1-x2)+abs(x3-x2),
            a3 = abs(x1-x3)+abs(x2-x3);

        cout << min(a1, min(a2, a3)) << '\n';
    }
}