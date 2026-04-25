#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--){
        int n, x, y;
        cin >> n >> x >> y;
        x = abs(x);
        y = abs(y);
        string s;
        cin >> s;

        int a = count(s.begin(), s.end(), '4');
        int b = count(s.begin(), s.end(), '8');

        if (x > y) swap(x, y);

        if (x <= b) {
            cout << ((y <= a + b) ? "YES" : "NO") << '\n';
        } else {
            x -= b;
            cout << ((y + x <= a + b) ? "YES" : "NO") << '\n';
        }
    }
}
