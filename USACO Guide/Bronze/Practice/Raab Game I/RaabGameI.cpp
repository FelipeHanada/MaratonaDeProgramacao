#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if ((a + b > n) || (max(a, b) > 0 && min(a, b) == 0)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i=1; i<=a; i++) cout << i + b << ' ';
    for (int i=1; i<=b; i++) cout << i << ' ';
    for (int i=a+b+1; i<=n; i++) cout << i << ' ';
    cout << '\n';

    for (int i=1; i<=n; i++) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) solve();
}