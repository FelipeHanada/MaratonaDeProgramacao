#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> v(32, 0);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;

        for (int i=0; a; i++) {
            if (a & 1)
                v[i]++;
            a >>= 1;
        }
    }

    for (int i=0; i<n; i++) {
        int a = 0, p = 1;
        for (int j=0; j<32; j++) {
            if (v[j]) {
                a += p;
                v[j]--;
            }
            p <<= 1;
        }
        cout << a << " ";
    }
    cout << "\n";
}