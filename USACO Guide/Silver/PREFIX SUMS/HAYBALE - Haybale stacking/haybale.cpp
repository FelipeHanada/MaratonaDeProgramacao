#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for (int i=0; i<k; i++) {
        int l, r;
        cin >> l >> r;
        a[l-1]++;
        a[r]--;
    }

    for (int i=1; i<=n; i++) {
        a[i] += a[i-1];
    }
    sort(a.begin(), a.end()-1);

    cout << a[n/2] << '\n';
}