#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, a, b, c;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b >> c;
        cout << "Case " << i + 1 << ": " << ((c % __gcd(a, b)) ? "No" : "Yes") << "\n";
    }
}