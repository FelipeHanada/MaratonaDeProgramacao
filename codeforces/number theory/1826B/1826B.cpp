#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;

        vector<int> a(n/2);
        for (int j=0; j<n/2; j++)
            cin >> a[j];

        if (n % 2) {
            int x; cin >> x;  // discards the middle term
        }
        
        for (int j=n/2 - 1; j>=0; j--) {
            int x; cin >> x;
            a[j] = abs(a[j] - x);
        }

        int g = 0;
        for (int ai : a)
            g = __gcd(g, ai);
        cout << g << "\n";
    }
}