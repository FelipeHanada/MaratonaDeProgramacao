#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n, m;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n >> m;
        cout << ((n % m) ? "NO" : "YES") << "\n";
    }
}