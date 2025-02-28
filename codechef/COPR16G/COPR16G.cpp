#include <bits/stdc++.h>
using namespace std;


int t, a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        int g = __gcd(a, b);

        if (g > 1)
            cout << -1 << "\n";
        else
            cout << a * b - a - b + 1 << "\n";
    }
}
