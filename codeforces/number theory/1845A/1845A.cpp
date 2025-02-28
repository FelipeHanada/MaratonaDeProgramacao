#include <bits/stdc++.h>
using namespace std;


void solve(int n, int k, int x) {
    if (x > 1) {
        cout << "YES\n";
        cout << n << "\n";
        for (int i=0; i<n; i++)
            cout << "1 ";
        cout << "\n";
        return;
    }

    if (n == 1 || k == 1) {
        cout << "NO\n";
        return;
    }

    // if it is even, then 2 ... 2 do the work
    // if it is not, n >= 3
    //    if k < 3, there is no way to do this
    //    if not, 3 2 ... 2 do the work

    if (n % 2 && k < 3) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << n / 2 << "\n";
    if (n % 2) {
        cout << "3 ";
        n -= 3;
    }
    for (int i=0; i<n/2; i++)
        cout << "2 ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k, x;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n >> k >> x;
        solve(n, k, x);
    }
}