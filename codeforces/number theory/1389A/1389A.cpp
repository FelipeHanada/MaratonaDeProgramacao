#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, l, r;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> l >> r;
        if (2*l > r)    
            cout << -1 << " " << -1 << "\n";
        else
            cout << l << " " << 2*l << "\n";
    }
}