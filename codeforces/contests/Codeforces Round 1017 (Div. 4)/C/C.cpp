#include <bits/stdc++.h>
using namespace std;


/*
1 6 2
6 2 4
2 4 3
*/

void solve() {
    int n;
    cin >> n;

    vector<int> v(2*n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i+1];
        sum += (i+1) + (n+i+1);
        sum -= v[i+1];
    }
    for (int i=1; i<n; i++) {
        int trash;
        for (int j=0; j<n-1; j++) cin >> trash;
        cin >> v[n+i];
        sum -= v[n+i];
    }
    cout << sum << ' ';
    for (int i=1; i<2*n; i++) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}