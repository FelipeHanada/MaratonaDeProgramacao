#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    ll k;
    cin >> n >> k;

    ll d[n];
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }

    ll m = k + 1;
    for (int i=1; i<n; i++) {
        m += min(d[i] - d[i-1], k + 1);
    }

    cout << m << endl;
}