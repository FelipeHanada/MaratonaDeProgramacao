#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    int b_prod = 1;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        b_prod *= x;
        if (2023 % b_prod || b_prod > 2023) {
            cout << "NO\n";
            for (int j=i+1; j<n; j++)
                cin >> x;
            return;
        }
    }

    cout << "YES\n";
    cout << 2023 / b_prod << " ";
    for (int m=0; m<k-1; m++)
        cout << "1 ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++)
        solve();
}