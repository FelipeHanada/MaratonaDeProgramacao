#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    int no_escape = n*n - k;

    if (no_escape == 0) {
        cout << "YES\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << "U";
            }
            cout << '\n';
        }
        return;
    }

    if (no_escape == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    no_escape -= 2;
    cout << "RL";
    for (int i=2; i<n; i++) {
        if (no_escape > 0) {
            cout << "L";
            no_escape--;
        } else {
            cout << "D";
        }
    }
    cout << '\n';
    for (int i=1; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (no_escape > 0) {
                cout << "U";
                no_escape--;
            } else {
                cout << "D";
            }
        }
        cout << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}