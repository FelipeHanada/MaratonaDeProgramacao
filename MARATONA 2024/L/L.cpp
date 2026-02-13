#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int v[32];
    fill_n(v, 32, 0);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        for (int j=0; x; j++) {
            if (x & 1) v[j]++;
            x >>= 1;
        }
    }

    for (int i=0; i<n; i++) {
        int x = 0, p = 1;
        for (int j=0; j<32; j++) {
            if (v[j]) {
                x += p;
                v[j]--;
            }
            p <<= 1;
        }

        cout << x << ' ';
    }
}
