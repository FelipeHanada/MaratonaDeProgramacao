#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        cout << ((n % 3 == 0) ? "Second" : "First") << "\n";
    }
}