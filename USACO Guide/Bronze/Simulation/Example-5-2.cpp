#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int c[n];
    int a[n];

    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n-1; i++) {
        int poured = min(c[i+1] - a[i+1], a[i]);
        a[i] -= poured;
        a[i + 1] += poured;
    }

    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}
