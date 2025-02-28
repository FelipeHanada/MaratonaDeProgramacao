#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, k;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> k;
        int y = 100 - k;
        int g = __gcd(k, y);
        cout << k/g + y/g << "\n";
    }
}