#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;

    int x[n];
    int prefix[n+1]; prefix[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        prefix[i + 1] = prefix[i] ^ x[i];
    }

    int a, b;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        cout << (prefix[a-1] ^ prefix[b]) << '\n';
    }
}
