#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i=1; i<=2*n; i++) {
        if ((i*i - k) % (2*n+1) == 0) {
            cout << i*i << '\n';
        }
    }
}