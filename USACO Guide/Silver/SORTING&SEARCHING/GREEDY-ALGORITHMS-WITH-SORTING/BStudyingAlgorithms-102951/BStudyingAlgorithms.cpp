#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);

    int k=0;
    for (; k<n && x >= a[k]; k++) {
        x -= a[k];
    }

    cout << k << endl;
}
